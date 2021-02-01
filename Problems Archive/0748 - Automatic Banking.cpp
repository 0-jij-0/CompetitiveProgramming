#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<int, int>> queries;
vector<pair<int, int>> coin;
vector<int> width;

struct StVal {
	ll v = 0; int vid = 0; StVal() {}
	StVal(const ll _v, int idx) : v(_v), vid(idx) {}
	StVal(const StVal &v1, const StVal &v2) {
		if (v1.v > v2.v) { v = v1.v; vid = v1.vid; }
		else { v = v2.v; vid = v2.vid; }
	}
	operator ll() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n); init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(coin[lo].second, lo);
			leaves[lo] = si;
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

	void update(const int i) {
		int si = leaves[i]; st[si] = StVal(-1, i);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

ll query(pair<int, int> q, SegTree &st) {
	int w = q.first, weight = q.second;
	int idx = upper_bound(width.begin(), width.end(), w) - width.begin() - 1;
	if (idx == -1) { return 0; }

	ll res = 0;
	while (true) {
		StVal s = st.query(0, idx);
		if (s.v < weight) { break; }
		res++; st.update(s.vid);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int s; cin >> s; queries.resize(s);
	for (auto &x : queries) { cin >> x.first >> x.second; }
	int c; cin >> c; coin.resize(c); width.resize(c);
	for (auto &x : coin) { cin >> x.first >> x.second; }
	for (int i = 0; i < c; i++) { width[i] = coin[i].first; }
	sort(coin.begin(), coin.end()); SegTree st(c);
	sort(width.begin(), width.end());

	ll res = 0;
	for (int i = 0; i < (int)queries.size(); i++)
		res += (i + 1) * query(queries[i], st);

	cout << res << endl;
	cin.ignore(2); return 0;
}