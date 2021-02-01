#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int weight(int n) {
	int res = 0;
	while (n) { res++; n &= n - 1; }
	return res;
}

int CTZ(int n) {
	int res = 0;
	while ((n & 1) == 0) { res++; n >>= 1; }
	return res;
}

int ChromaticNumber(const vector<int>& g) {
	int n = g.size(); if (n == 0) return 0;
	//randomly choose a large prime
	const int mod = 1077563119, all = 1 << n;
	vector<int> ind(all), s(all);

	for (int i = 0; i < all; i++) 
		s[i] = ((n - weight(i)) & 1 ? -1 : 1);

	ind[0] = 1; for (int i = 1; i < all; i++) {
		int ctz = CTZ(i);
		ind[i] = ind[i - (1 << ctz)] + ind[(i - (1 << ctz)) & ~g[ctz]];
		if (ind[i] >= mod) ind[i] -= mod;
	}

	//compute the chromatic number (= \sum (-1)^{n - |i|} * ind(i)^k)
	for (int k = 1; k < n; k++) {
		ll sum = 0;
		for (int i = 0; i < all; i++) {
			ll cur = s[i] * (ll)ind[i];
			s[i] = cur % mod; sum += cur;
		}
		if (sum % mod) return k;
	}
	return n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	vector<int> g(n, (1 << n) - 1);
	for (int i = 0; i < n; i++) g[i] ^= (1 << i);

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a] ^= (1 << b); g[b] ^= (1 << a);
	}

	cout << ChromaticNumber(g) << '\n';

	cin.ignore(2); return 0;
}