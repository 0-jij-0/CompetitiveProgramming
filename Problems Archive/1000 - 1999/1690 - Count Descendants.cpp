#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> start, finish, order;
const int MIN = 0, MAX = 2e5 + 5; //Min and max possible values in the array; [-1e9,1e9] are too much --> compress
vector<int> A, B; //A used to build wavelet tree B copy of A

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
		nodes[v].edges.emplace_back(v, u);
	}

	void preorder(int u, int& t) {
		start[u] = t; t++; order.push_back(u);
		for (auto& x : nodes[u].edges) {
			if (start[x.v] == -1) { preorder(x.v, t); }
		}
		finish[u] = t - 1;
	}

	void depth(int cur, int d, int p = -1) {
		A[start[cur]] = d; for(edge &e : nodes[cur].edges)
			if (e.v != p) { depth(e.v, d + 1, cur); }
	}
};

struct WaveletTree {
	int lVal, rVal; int n;
	WaveletTree* lC, * rC;
	vector<int> left; 		
	WaveletTree(int _n) : WaveletTree(0, n = _n - 1, MIN, MAX) {}

	WaveletTree(int lo, int hi, int x, int y) {
		lVal = x; rVal = y;
		if (lVal == rVal || hi < lo) { lC = rC = nullptr; return; }

		int mid = (lVal + rVal) >> 1;
		auto f = [&](const int& x) { left.push_back(x <= mid); };
		for_each(A.begin() + lo, A.begin() + hi + 1, f);
		partial_sum(left.begin(), left.end(), left.begin());

		auto comp = [&](const int& x) { return x <= mid; };
		int pivot = stable_partition(A.begin() + lo, A.begin() + hi + 1, comp) - A.begin();
		lC = new WaveletTree(lo, pivot - 1, lVal, mid);
		rC = new WaveletTree(pivot, hi, mid + 1, rVal);
	}

	//Query #3: #numbers = k in [l, r]
	int countK(int l, int r, int k) {
		if (l > r || k < lVal || k > rVal) { return 0; }
		if (lVal == rVal) { return r - l + 1; }

		int mid = (lVal + rVal) >> 1, befL = (l ? left[l - 1] : 0);
		if (k <= mid) { return lC->countK(befL, left[r] - 1, k); }
		return rC->countK(l - befL, r - left[r], k);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	start.resize(n, -1); finish.resize(n); A.resize(n);
	for (int i = 1; i < n; i++) {
		int p; cin >> p; g.add_edge(i, --p);
	}

	int t = 0; g.preorder(0, t); g.depth(0, 0);
	WaveletTree wt(n); int q; cin >> q; 
	
	while (q--) {
		int u, d; cin >> u >> d; --u;
		int L = start[u], R = finish[u];
		cout << wt.countK(L, R, d) << '\n';
	}

	cin.ignore(2); return 0;
}