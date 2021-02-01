#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SVSZ = 1000 * 1000 * 10 + 1;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<map<int, int>> v;

int spf[SVSZ]; //Smallest Prime Factor

void buildSieve() {
	vector<int> primes; spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}
inline void fact(int i, int x) {
	while (x != 1) {
		int s = spf[x]; int c = 0;
		while (x % s == 0) { c++; x /= s; }
		v[i][s] += c;
	}
}

ll power(int x, int n) {
	ll res = 1, a = x;
	for (; n; n >>= 1, a = (a * a) % mod)
		if (n & 1) res = (res * a) % mod;
	return res;
}

int main() {
	int n; cin >> n; v.resize(n); buildSieve();
	for (int i = 0; i < n; i++) {
		int m; cin >> m; while (m--) {
			int x; cin >> x; fact(i, x);
		}
	}
	ll res = 1; for (auto &x : v[0]) {
		int c = 1 << 30; for (int i = 0; i < n; i++) {
			if (!v[i].count(x.first)) { c = 0; break; }
			c = min(c, v[i][x.first]);
		}
		res = (res * power(x.first, c)) % mod;
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}