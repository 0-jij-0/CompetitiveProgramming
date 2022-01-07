#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> v;
vector<int> versions;	//contains the root of each version, 1-based since version 0 is the empty segtree

struct StVal {
	StVal * left = NULL, * right = NULL;
	ll sum = 0; int idx = 0; StVal() {}
	StVal(const ll _v, int i) : sum(_v), idx(i) { left = right = NULL; }
	StVal(StVal* v1, StVal* v2, int i) : idx(i) {	//v1, v2 are never NULL
		sum = *v1 + *v2; left = v1; right = v2;
	}
	operator ll() const { return sum; }
};

struct PSSegTree {
	int n, last = 0;
	vector<StVal*> st;	//st[1] is the root

	PSSegTree(const int n) : n(n) { 
		init(1, 0, n - 1); 
		last = (int)st.size();
		versions.push_back(1);
	}

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = new StVal(v[lo], si);
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = new StVal(st[si << 1], st[si << 1 | 1], si);
		}
	}

	//l and r inclusive, 0-indexed, version v
	StVal* query(const int l, const int r, const int v = 0) {
		return (l <= r && l < n && r >= 0) ? query(l, r, st[versions[v]], 0, n - 1) : new StVal();
	}
	StVal* query(const int l, const int r, StVal* si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return si;

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si->left, lo, mid);
		if (mid < l) return query(l, r, si->right, mid + 1, hi);
		return new StVal(query(l, r, si->left, lo, mid), query(l, r, si->right, mid + 1, hi), 0);
	}

	//PERSISTENT UPDATE
	//v version, i idx, x new VALUE
	void PSUpdate(int v, int i, ll x) {
		//increment by nx, remove if we want to assign or if the query returns smthg else
		ll inc = x - query(i, i, v)->sum;
		PSUpdate(0, n - 1, i, inc, versions[v]);
	}
	int PSUpdate(int lo, int hi, int i, ll inc, int &curRoot, bool b = true) {
		st.push_back(new StVal(st[curRoot]->sum + inc, last)); 
		st[last]->left = st[curRoot]->left;
		st[last]->right = st[curRoot]->right;
		if (b) curRoot = last; int idx = last++;

		if (lo == hi) return idx; int mid = (lo + hi) >> 1;
		if (i <= mid) st[idx]->left = st[PSUpdate(lo, mid, i, inc, st[idx]->left->idx, false)];
		else st[idx]->right = st[PSUpdate(mid + 1, hi, i, inc, st[idx]->right->idx, false)];
		return idx;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q; v.resize(n);
	for (auto& x : v) { cin >> x; }

	PSSegTree pst(n); while (q--) {
		int t, k; cin >> t >> k; k--;
		if (t == 1) {
			int a, x; cin >> a >> x;
			pst.PSUpdate(k, --a, x);
		}
		else if (t == 2) {
			int a, b; cin >> a >> b;
			cout << pst.query(--a, --b, k)->sum << '\n';
		}
		else { versions.push_back(versions[k]); }
	}

	cin.ignore(2); return 0;
}