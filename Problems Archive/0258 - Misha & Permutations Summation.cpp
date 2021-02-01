#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

template<class V> struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	V query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V(); }
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i) {
		int si = leaves[i]; st[si].v--;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}

	int find(int x) {
		int si = 1, lo = 0, hi = n - 1, sum = 0;
		while (lo != hi) {
			int mid = (lo + hi) >> 1, l = si << 1, r = l | 1;
			if (st[l] + sum - 1 >= x) { si = l; hi = mid; }
			else { si = r; lo = mid + 1; sum += st[l].v; }
		}
		return lo;
	}
};

struct StVal { // define
	int v = 1; // optional
	StVal() {}
	StVal(const int _v) : v(_v) {} // optional
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator int() const { return v; } // optional
};

typedef SegTree<StVal> MyST;
vector<int> p, q; int n;

void fact_base(vector<int> &v) {
	MyST st(n);
	for (auto &x : v) {
		int y = x; x = st.query(0, x) - 1; st.update(y);
	}
}

vector<int> fact_sum(vector<int> &p, vector<int> &q) {
	vector<int> res(n); int c = 0;
	for (int i = 0; i < n; i++) {
		int mod = i + 1, x = p[n - 1 - i] + q[n - 1 - i] + c;
		res[n - 1 - i] = x % mod; c = x / mod;
	}
	return move(res);
}

void build_perm(vector<int> &v) {
	MyST st(n);
	for (auto &x : v) {
		x = st.find(x);	st.update(x);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n; p.resize(n); q.resize(n);
	for (auto &x : p) { cin >> x; }
	for (auto &x : q) { cin >> x; }
	fact_base(p); fact_base(q);
	vector<int> res = fact_sum(p, q);
	//for (auto &x : res) { cout << x << ' '; }
	build_perm(res);

	for (int i = 0; i < n; i++) {
		cout << res[i];
		if (i + 1 != n) { cout << ' '; }
		else { cout << endl; }
	}

	cin.ignore(2); return 0;
}