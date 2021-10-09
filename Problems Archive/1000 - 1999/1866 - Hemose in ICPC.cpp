#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <numeric>
#include <set>
using namespace std;

vector<pair<int, int>> ETT;

int query(int l, int r) {
	set<int> s; for (int i = l; i <= r; i++) {
		s.insert(ETT[i].first);
		s.insert(ETT[i].second);
	}
	string q = "? " + to_string((int)s.size());
	for (auto& x : s) q += " " + to_string(x);
	cout << q << endl; int R; cin >> R; return R;
}

struct graph {
	vector<vector<int>> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v) {
		nodes[u].emplace_back(v);
		nodes[v].emplace_back(u);
	}
};

void eulerTourTree(graph& g, int cur, int p = -1) {
	for (auto& e : g.nodes[cur]) if (e != p) {
		ETT.emplace_back(cur, e);
		eulerTourTree(g, e, cur);
		ETT.emplace_back(e, cur);
	}
}

int main() {
	int n; cin >> n; graph g(n + 1);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
	}

	eulerTourTree(g, 1); n = (int)ETT.size();
	int maxDist = query(0, n - 1);
	int l = 0, r = n - 1; 

	while (l != r) {
		int mid = (l + r) >> 1;
		int d = query(l, mid);
		d == maxDist ? r = mid : l = mid + 1;
	}

	string res = "! " + to_string(ETT[l].first) + " " + to_string(ETT[l].second);
	cout << res << endl; cin.ignore(2); return 0;
}