#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
typedef long long ll;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { // sum from 0 ... i
		if (i < 0 || i >= n) { return 0; }
		assert(i >= -1 && i < n); ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<ll> res; vector<int> a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; res.resize(n); 
	a.resize(n); FT ft(n);

	ll cur = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; ft.update(a[i], 1);
		cur += ft.query(a[i] + 1, n - 1);
	}
	res[0] = cur;
	for (int i = 0; i < n - 1; i++) {
		cur -= ft.query(0, a[i] - 1);
		cur += ft.query(a[i] + 1, n - 1);
		res[i + 1] = cur;
	}

	for (auto& x : res) cout << x << '\n';
	cin.ignore(2); return 0;
}