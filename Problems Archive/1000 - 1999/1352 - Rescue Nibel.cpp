#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<pair<int, int>> add;
vector<ll> fact(300005, 1);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

ll choose(int n, int k) {
	ll den = (fact[k] * fact[n - k]) % mod;
	return (fact[n] * modInv(den)) % mod;
}

int main() {
	int n, k; cin >> n >> k; add.resize(n);
	for (int i = 1; i < 300005; i++) fact[i] = (i * fact[i - 1]) % mod;
	for (auto &x : add) { cin >> x.first >> x.second; }
	sort(add.begin(), add.end()); multiset<int> rem;

	ll res = 0; for (int i = 0; i < n; i++) {
		rem.insert(add[i].second);
		while (*rem.begin() < add[i].first) { rem.erase(rem.begin()); }
		int c = (int)rem.size(); if (c >= k) { res = (res + choose(c - 1, k - 1)) % mod; }
	}
	cout << res << '\n'; cin.ignore(2); return 0;
}