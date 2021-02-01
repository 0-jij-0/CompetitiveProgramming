#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
using namespace std;

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
		edge e1(u, v);
		nodes[u].edges.push_back(e1);
	}

	bool dfs(int src, int dst) {
		vector<bool> visited(n, false);
		stack<int> s; s.push(src);
		visited[src] = true;
		while (!s.empty()) {
			int f = s.top(); s.pop();
			if (f == dst) { return true; }
			node& n = nodes[f];
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					s.push(dest); visited[dest] = true;
				}
			}
		}
		return false;
	}
};

set<string> s; map<string, int> idx;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, m; cin >> n >> m; graph g(401);
	int last = 0; int u, v;
	for (int i = 0; i < n; i++) {
		string a, b, z;	cin >> a >> z >> z >> z >> b;
		if (s.count(a)) { u = idx[a]; }
		else { s.insert(a); u = idx[a] = last; last++; }
		if (s.count(b)) { v = idx[b]; }
		else { s.insert(b); v = idx[b] = last; last++; }
		g.add_edge(u, v);
	}
	vector<string> res;
	for (int i = 0; i < m; i++) {
		string a, b, z; cin >> a >> z >> z >> z >> b;
		if (!s.count(a)) { res.push_back("Pants on Fire"); continue; }
		if (!s.count(b)) { res.push_back("Pants on Fire"); continue; }
		u = idx[a], v = idx[b];
		if (g.dfs(u, v)) { res.push_back("Fact"); continue; }
		if (g.dfs(v, u)) { res.push_back("Alternative Fact"); continue; }
		res.push_back("Pants on Fire");
	}
	for (auto &x : res) { cout << x << endl; }
	cin.ignore(2); return 0;
}