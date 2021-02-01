#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

template<class V>
struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n, 0);
		init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = 0;
			leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
		}
	}

	V query() { return st[1]; }

	// ------------------------------------------| ________ |---------------------------------------------------------
	// ------------------------------------------| NON-LAZY |---------------------------------------------------------

	void update(const int i, V v) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		st[si] = v; bool b = false;
		for (si >>= 1; si; si >>= 1) {
			if (!b) { st[si] = st[si << 1] | st[si << 1 | 1]; }
			else { st[si] = st[si << 1] ^ st[si << 1 | 1]; }
			b = !b;
		}
	}
};

struct StVal { // define
	ll v = 0; // optional
	StVal() {}
	StVal(const ll v) : v(v) {} // optional
	operator ll() const { return v; } // optional
};

typedef SegTree<StVal> MyST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	int N = 1 << n;
	MyST st(N);
	for (int i = 0; i < N; i++) {
		long long a; cin >> a;
		st.update(i, a);
	}

	for (int i = 0; i < m; i++) {
		int p; long long b; cin >> p >> b;
		StVal s(b); st.update(p - 1, s);
		cout << st.query() << endl;
	}

	cin.ignore(2); return 0;
}