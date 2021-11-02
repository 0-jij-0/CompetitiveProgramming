#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

struct StVal {
	int mi = 1 << 30, id = -1; StVal() {}
	StVal(const int _v, int i) : mi(_v), id(i) {}
	StVal(const StVal& v1, const StVal& v2) { 
		if (v2 < v1) { mi = v2.mi; id = v2.id; }
		else { mi = v1.mi; id = v1.id; }
	}
	operator int() const { return mi; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(0, lo); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	int query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1).id : -1; }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i) {
		int si = leaves[i]; st[si].mi = 1;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x.second >> x.first;
		auto comp = [&](int& i, int& j) { return v[i] < v[j]; };
		vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), comp);

		vector<int> res(n); bool ok = true; SegTree st(n);
		for (auto& i : idx) {
			int id = st.query(--v[i].second, --v[i].first);
			if (res[id]) { ok = false; break; }
			res[id] = i + 1; st.update(id);
		}

		if (!ok) { cout << "impossible\n"; continue; }
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}