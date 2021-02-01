#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal &v1, const StVal &v2) { v = (v1 + v2) % mod; }
	operator ll() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, const ll x) {
		int si = leaves[i]; st[si].v = x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

map<int, int> comp;
vector<vector<int>> idx;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; comp[x]; }
	int id = 0; for (auto &x : comp) { x.second = id++; }
	idx.resize(id); for (int i = 0; i < n; i++) {
		v[i] = comp[v[i]]; idx[v[i]].push_back(i);
	}
	SegTree st(n); for (auto &x : idx) {
		int m = (int) x.size();
		for (int i = m - 1; i >= 0; i--)
			st.update(x[i], 1 + st.query(0, x[i] - 1));
	}

	ll res = 0; for (int i = 0; i < n; i++)
		res = (res + st.st[st.leaves[i]].v) % mod;
	cout << res << '\n'; cin.ignore(2); return 0;
}