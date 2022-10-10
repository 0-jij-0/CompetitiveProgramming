#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> value;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = max(v1, v2); }
	operator ll() const { return v; }
};

struct SegTree {
	vector<StVal> st;
	vector<int> leaves;
	int n = 0; SegTree() {}

	SegTree(const int n, vector<int>& arr) : n(n), leaves(n) { init(1, 0, n - 1, arr); }

	void init(const int si, const int lo, const int hi, vector<int>& arr) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(value[arr[lo]]); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, arr);
			init(si << 1 | 1, mid + 1, hi, arr);
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

	void update(const int i, int x) {
		int si = leaves[i]; st[si] = x;
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

struct HLDTree {
	vector<vector<int>> nodes; int n;
	vector<int> par, depth, subtreeSize; //For LCA and Heavy Edges
	vector<int> segtreeIDX, pathIDX, nextPath;
	vector<vector<int>> heavyPaths;
	vector<SegTree> st;

	HLDTree(int _n) : n(_n), nodes(_n), depth(_n, 0), par(n, -1),
		subtreeSize(_n, 1), segtreeIDX(_n), pathIDX(_n) {
		value.resize(n); for (auto& x : value) cin >> x;
		for (int i = 1; i < _n; i++) {
			int u, v; cin >> u >> v;
			add_edge(--u, --v);
		}

		initDFS(0); initHLD();
	}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}

	//Finds parents, depths & substreeSizes
	int initDFS(int cur, int p = -1) {
		for (auto& e : nodes[cur]) if (e != p) {
			par[e] = cur; depth[e] = 1 + depth[cur];
			subtreeSize[cur] += initDFS(e, cur);
		}
		return subtreeSize[cur];
	}

	//Computes Heavy-Paths
	void initHLD() {
		vector<int>	orderBFS(n);
		iota(orderBFS.begin(), orderBFS.end(), 0);
		auto depthOrder = [&](int& i, int& j) { return depth[i] < depth[j]; };
		sort(orderBFS.begin(), orderBFS.end(), depthOrder);

		for (int i = n - 1; i >= 0; i--) {
			bool newPaths = true; int cur = orderBFS[i];
			int subSize = subtreeSize[cur];
			int heavy = (subSize + (subSize & 1)) >> 1;

			for (auto& e : nodes[cur]) if(e != par[cur]) {
				//End of previous heavy path
				if (subtreeSize[e] < heavy) { addHeavyPath(e, cur); continue; }

				newPaths = false; pathIDX[cur] = pathIDX[e];
				heavyPaths[pathIDX[cur]].push_back(cur);
			}
			if (newPaths) { //Node doesn't have a down heavy edge
				pathIDX[orderBFS[i]] = (int)heavyPaths.size();
				heavyPaths.push_back({ orderBFS[i] });
				st.emplace_back(); nextPath.emplace_back(-1);
			}
		}

		addHeavyPath(0); for (int i = 0; i < (int)nextPath.size(); i++)
			if (nextPath[i] != -1) nextPath[i] = pathIDX[nextPath[i]];
	}

	//Adds a Heavy Path, Initializes Corresponding Segment Trees
	void addHeavyPath(int u, int p = -1) {
		int idx = pathIDX[u], m = (int)heavyPaths[idx].size();
		reverse(heavyPaths[idx].begin(), heavyPaths[idx].end());
		for (int i = 0; i < m; i++)
			segtreeIDX[heavyPaths[idx][i]] = i;

		st[idx] = SegTree(m, heavyPaths[idx]);
		nextPath[idx] = p;
	}

	StVal query(int a, int b) {
		int A = pathIDX[a], B = pathIDX[b];

		StVal res = StVal(); while (A != B) {
			if (depth[heavyPaths[A][0]] < depth[heavyPaths[B][0]]) { swap(A, B); swap(a, b); }
			res = StVal(res, st[A].query(0, segtreeIDX[a]));
			a = par[heavyPaths[A][0]]; A = nextPath[A];
		}
		int L = min(segtreeIDX[a], segtreeIDX[b]);
		int R = max(segtreeIDX[a], segtreeIDX[b]);
		return StVal(res, st[A].query(L, R));
	}

	void pointUpdate(int a, int x) {
		st[pathIDX[a]].update(segtreeIDX[a], x);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	HLDTree hld(n); while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int s, x; cin >> s >> x; s--;
			hld.pointUpdate(s, x);
		}
		else {
			int a, b; cin >> a >> b; a--; b--;
			cout << hld.query(a, b) << '\n';
		}
	}
}