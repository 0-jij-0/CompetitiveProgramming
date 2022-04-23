#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll power(ll x, int n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

string s;

vector<string> hashes;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> s;
	hashes.resize(1 << n); s.insert(s.begin(), '0');
	int nonLeaf = (1 << n) - 1 - (1 << (n - 1));

	for (int i = (1 << n) - 1; i > nonLeaf; i--) 
		hashes[i] = string(1, s[i]);

	int cnt = 0;
	for (int i = nonLeaf; i > 0; i--) {
		cnt += hashes[i << 1] != hashes[i << 1 | 1];
		string mi = min(hashes[i << 1], hashes[i << 1 | 1]);
		string ma = max(hashes[i << 1], hashes[i << 1 | 1]);
		hashes[i] = mi + string(1, s[i]) + ma;
	}

	cout << power(2, cnt) << '\n';
	cin.ignore(2); return 0;
}