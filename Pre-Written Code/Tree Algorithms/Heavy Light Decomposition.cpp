#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;
typedef long long ll;

vector<ll> value;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& L, const StVal& R) { v = max(L, R); }
	operator ll() const { return v; }
};

struct StUpdate {
	ll u = 0; StUpdate() {}
	StUpdate(const ll u) : u(u) {}
	StUpdate(const StUpdate& oldU, const StUpdate& newU) { u = oldU + newU; }
	operator ll() const { return u; }
	void apply(StVal& v, const int lo, const int hi) { v.v += u; }
};

struct SegTree {
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;
	int n = 0; SegTree() {}

	SegTree(const int n, vector<int> &arr) : n(n), leaves(n) {
		init(1, 0, n - 1, arr); lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi, vector<int> &arr) {
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

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate& u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = StUpdate(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, StUpdate U) {
		int si = leaves[i]; lazy[si] = StUpdate(lazy[si], U);
		updateLazy(si, i, i); for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
};

struct Edge {
	int u, v; Edge() {}
	Edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct HLDTree {
	vector<vector<Edge>> nodes; int n; //Change based on N
	vector<int> par, depth, subtreeSize; //Required Information for HLD
	vector<int> segtreeIDX, pathIDX, nextPath;
	vector<vector<int>> heavyPaths;
	vector<SegTree> st;

	HLDTree(int _n) : n(_n), nodes(_n), depth(_n, 0), par(_n),
		subtreeSize(_n, 1),	segtreeIDX(_n), pathIDX(_n) {
		
		value.resize(n); for (auto& x : value) cin >> x;
		for (int i = 1; i < _n; i++) {
			int u, v; cin >> u >> v;
			addEdge(--u, --v);
		}

		initDFS(0); initHLD();
	}

	void addEdge(int u, int v) {
		nodes[u].emplace_back(u, v);
		nodes[v].emplace_back(v, u);
	}

	//Finds parents, depths & substreeSizes
	int initDFS(int cur, int p = -1) { 
		for (auto& e : nodes[cur]) if (e.v != p) {
			par[e.v] = cur; depth[e.v] = 1 + depth[cur];
			subtreeSize[cur] += initDFS(e.v, cur);
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

			for (auto& e : nodes[cur]) {
				if (e.v == par[cur]) { continue; }

				//End of previous heavy path
				if (subtreeSize[e.v] < heavy) { addHeavyPath(e.v, cur); continue; }

				newPaths = false; pathIDX[cur] = pathIDX[e.v];
				heavyPaths[pathIDX[cur]].push_back(cur);
			}
			if (newPaths) { //Node doesn't have a down heavy edge
				pathIDX[orderBFS[i]] = (int)heavyPaths.size();
				heavyPaths.push_back({ orderBFS[i] });
				st.emplace_back(); nextPath.emplace_back(-1);
			}
		}

		addHeavyPath(0); for (int i = 0; i < (int)nextPath.size(); i++)
			if(nextPath[i] != -1) nextPath[i] = pathIDX[nextPath[i]];
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

	StVal query(int a, int b) { //O(log^2(n))
		int A = pathIDX[a], B = pathIDX[b];
		StVal res = StVal(); while (A != B) {
			if (depth[heavyPaths[A][0]] < depth[heavyPaths[B][0]]) { swap(A, B); swap(a, b); }
			res = StVal(res, st[A].query(0, segtreeIDX[a]));
			a = par[heavyPaths[A][0]]; A = nextPath[A];
		}
		if (segtreeIDX[a] > segtreeIDX[b]) { swap(a, b); }
		return StVal(res, st[A].query(segtreeIDX[a], segtreeIDX[b]));
	}

	void pointUpdate(int a, StUpdate U) {
		st[pathIDX[a]].update(segtreeIDX[a], U);
	}
	void rangeUpdate(int a, int b, StUpdate U) { //O(log^2(n))
		int A = pathIDX[a], B = pathIDX[b];
		while (A != B) {
			if (depth[heavyPaths[A][0]] < depth[heavyPaths[B][0]]) { swap(A, B); swap(a, b); }
			st[A].update(0, segtreeIDX[a], U);
			a = par[heavyPaths[A][0]]; A = nextPath[A];
		}
		if (segtreeIDX[a] > segtreeIDX[b]) { swap(a, b); }
		st[A].update(segtreeIDX[a], segtreeIDX[b], U);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
}