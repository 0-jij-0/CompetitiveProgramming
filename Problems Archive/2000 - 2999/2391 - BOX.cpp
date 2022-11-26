#include <bits/stdc++.h>
using namespace std;

vector<int> boxes, names; int boxNum = 0;

struct DSU {
	vector<int> rank, par; int N;

	DSU(int n) : N(n), rank(n, 1), par(n) { iota(par.begin(), par.end(), 0); }

	int find(const int& u) { return par[u] == u ? u : (par[u] = find(par[u])); }

	void merge(int u, int v) {
		if (rank[v] == 0) { return; }
		rank[u] += rank[v];	par[v] = u;
		boxes[names[v]] = N + boxNum;
		names.push_back(names[v]);
		rank.push_back(0);
		par.push_back(N + boxNum);
		boxNum++;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; 
	boxes.resize(n); names.resize(n + q);
	iota(boxes.begin(), boxes.end(), 0);
	iota(names.begin(), names.end(), 0);
	DSU dsu(n + q); int total = n;
	
	while (q--) {
		int t, x; cin >> t >> x; 
		if (t == 1) { int y; cin >> y; dsu.merge(boxes[--x], boxes[--y]); }
		if (t == 2) { dsu.rank[boxes[--x]]++; dsu.par[total++] = boxes[x]; }
		if (t == 3) { cout << names[dsu.find(--x)] + 1 << '\n'; }
	}
}