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
		assert(i >= -1 && i < n); ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; 
	FT ft(n); v.resize(n);
	for (int i = 0; i < n; i++) {
		int x; cin >> x; ft.update(i, v[i] = x);
	}
	while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if(t == 1) {
			a--; ft.update(a, -v[a]);
			ft.update(a, v[a] = b);
		}
		else { cout << ft.query(--a, --b) << endl; }
	}
	cin.ignore(2); return 0;
}