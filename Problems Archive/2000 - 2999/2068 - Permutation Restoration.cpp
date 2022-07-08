#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<int> v, L, R, idx;

struct StVal {
	pair<int, int> p; bool b = true; StVal() {}
	StVal(const int _v, const int _i) : p({ _v, _i }) {}
	StVal(const StVal& v1, const StVal& v2) { 
		if(v1.b && v2.b) p = max(v1.p, v2.p);
		else { p = v1.b ? v1.p : v2.p; }
		b = v1.b || v2.b;
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(L[idx[lo]], lo); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i) {
		int si = leaves[i]; st[si].b = false;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	auto comp = [&](const int& i, const int& j) {
		return R[i] < R[j];
	};

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		L.resize(n); R.resize(n);
		for (int i = 0; i < n; i++) {
			L[i] = ((i + 1) / (v[i] + 1)) + 1;
			R[i] = v[i] ? ((i + 1) / v[i]) : n;
		}
		idx.resize(n); iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), comp);
		sort(R.begin(), R.end());

		vector<int> res(n); SegTree st(n);
		for (int i = n; i > 0; i--) {
			int l = lower_bound(R.begin(), R.end(), i) - R.begin();
			int id = st.query(l, n - 1).p.second;
			res[idx[id]] = i; st.update(id);
		}
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}