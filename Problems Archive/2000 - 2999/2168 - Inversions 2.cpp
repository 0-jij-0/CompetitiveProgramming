#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

struct StVal {
	int sum = 1; StVal() {}
	StVal(const int v) : sum(v) {}
	StVal(const StVal& v1, const StVal& v2) { sum = v1.sum + v2.sum; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	int query(int k) { return query(1, 0, n - 1, k); }
	int query(const int si, const int lo, const int hi, int k) {
		if (lo == hi) { update(lo); return lo; }
		const int mid = (lo + hi) >> 1;
		if (st[si << 1 | 1].sum > k) { return query(si << 1 | 1, mid + 1, hi, k); }
		return query(si << 1, lo, mid, k - st[si << 1 | 1].sum);
	}

	void update(const int i) {
		int si = leaves[i]; st[si].sum = 0;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; A.resize(n);
	for (auto& x : A) { cin >> x; }
	SegTree st(n + 1); vector<int> res(n);
	
	for (int i = n - 1; i >= 0; i--)
		res[i] = st.query(A[i]);

	for (auto& x : res) cout << x << ' '; cout << '\n';
}