#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <numeric>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n); ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum % mod;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> comp, v, leq, firstLeq;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; comp.push_back(x); }
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for (auto& x : v) x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();

	vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
	auto comp = [&](const int& i, const int& j) {
		if (v[i] != v[j]) { return v[i] < v[j]; }
		return i < j;
	}; sort(idx.begin(), idx.end(), comp);

	FT ft(n); ll res = 0; for (auto& i : idx) {
		res = (res + ft.query(0, i - 1) * modInv(power(2, n - i))) % mod;
		ft.update(i, power(2, n - 1 - i));
	}

	cout << res << '\n';
	cin.ignore(2); return 0;
}