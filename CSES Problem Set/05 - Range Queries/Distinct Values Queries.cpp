#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef int ll;

struct FT {
	int n; vector<ll> vals;
	FT(int n) : n(n), vals(n + 1, 0ll) {}

	void update(int i, ll x) {
		if (i < 0) { return; }
		for (++i; i <= n; i += i & -i) { vals[i] += x; }
	}

	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n); ll sum = 0;
		for (++i; i; i -= i & -i) { sum += vals[i]; }
		return sum;
	}
	ll query(int i, int j) const { return query(j) - query(i - 1); }
};

struct query {
	int l, r, idx; query() {}
	query(int _l, int _r, int _i) : l(_l), r(_r), idx(_i) {}
	bool operator < (const query& rhs) const { return r < rhs.r; }
};

vector<int> v, comp; vector<query> Q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; v.resize(n); Q.resize(q);
	for (auto& x : v) { cin >> x; comp.push_back(x); }
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		Q[i] = query(--l, --r, i);
	}

	sort(comp.begin(), comp.end()); sort(Q.begin(), Q.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for (auto& x : v) x = lower_bound(comp.begin(), comp.end(), x) - comp.begin();
	vector<int> last(comp.size(), -1), res(q); FT ft(n);

	int i = 0, j = 0; while (j != q) {
		ft.update(i, 1); ft.update(last[v[i]], -1); last[v[i]] = i; i++;
		while (j != q && Q[j].r == i - 1) { res[Q[j].idx] = ft.query(Q[j].l, Q[j].r); j++; }
	}

	for (auto& x : res) cout << x << '\n';

	cin.ignore(2); return 0;
}