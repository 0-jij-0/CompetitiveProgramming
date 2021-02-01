#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> m;
vector<string> name;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<vector<int>> D, helper;
	int cycle_start, cycle_end, cycle_length;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
	}

	void allPairsShortestPath() {
		int n = nodes.size(), max = n + 5;
		D.resize(n); for (int i = 0; i < n; i++) { D[i].resize(n, max); }
		helper.resize(n); for (int i = 0; i < n; i++) { helper[i].resize(n, -1); }

		for (auto &x : nodes) for (auto &y : x.edges) D[y.u][y.v] = 1;

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (D[i][k] + D[k][j] < D[i][j]) {
						D[i][j] = D[i][k] + D[k][j];
						helper[i][j] = k;
					}
	}

	void APSP_printPath(int s, int d) {
		if (helper[s][d] == -1) { cout << name[s] << " "; return; }
		APSP_printPath(s, helper[s][d]);
		APSP_printPath(helper[s][d], d);
	}

	void find_cycle() {
		allPairsShortestPath();
		int min_idx = -1, min = n + 1;
		for(int i = 0; i < n; i++)
			if (D[i][i] < min) { min = D[i][i]; min_idx = i; }
		if (min == n + 1) { cout << "SHIP IT" << endl; }
		else { APSP_printPath(min_idx, min_idx); cout << endl; }
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n; graph g(n);
	for (int i = 0; i < n; i++) { string s; cin >> s; m[s] = 0; }
	int id = 0; for (auto &x : m) { x.second = id; name.push_back(x.first); id++; }
	for (int i = 0; i < n; i++) {
		int e; string s; cin >> s >> e; int u = m[s];
		for (int j = 0; j < e; j++) {
			string x; cin >> x >> x;
			while (x.back() == ',') {
				x.pop_back(); int v = m[x]; 
				g.add_edge(u, v); cin >> x;
			}
			int v = m[x]; g.add_edge(u, v);
		}
	}
	g.find_cycle(); cin.ignore(2); return 0;
}