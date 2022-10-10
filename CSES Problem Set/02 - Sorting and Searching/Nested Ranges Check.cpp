#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<pair<pair<int, int>, int>> v;
vector<int> res1, res2;

struct StVal {
	ll mi = 1 << 30, ma = -(1 << 30); StVal() {}
	StVal(const ll _v) : mi(_v), ma(_v) {}
	StVal(const StVal& v1, const StVal& v2) {
		mi = min(v1.mi, v2.mi);
		ma = max(v1.ma, v2.ma);
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
			st[si] = StVal(v[lo].first.second); leaves[lo] = si;
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
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n); 
	res1.resize(n); res2.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first.first >> v[i].first.second;
		v[i].second = i;
	}
	
	auto comp = [&](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2) { 
		if (p1.first.first != p2.first.first) return p1.first.first < p2.first.first;
		return p1.first.second > p2.first.second;
	}; sort(v.begin(), v.end(), comp); SegTree st(n);

	for (int i = 0; i < n; i++) {
		res1[v[i].second] = st.query(i + 1, n - 1).mi <= v[i].first.second;
		res2[v[i].second] = st.query(0, i - 1).ma >= v[i].first.second;
	}

	for (auto& x : res1) cout << x << ' '; cout << '\n';
	for (auto& x : res2) cout << x << ' '; cout << '\n';

	cin.ignore(2); return 0;
}