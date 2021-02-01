#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { int id; vector<edge> edges; };

struct graph {
	vector<node> nodes;
	int n;

	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
	}

	bool cycle_dfs(int u, vector<int> &color, vector<int> &parent) {
		color[u] = 1;
		for (auto x : nodes[u].edges) {
			int v = x.v;
			if (color[v] == 0) {
				parent[v] = u;
				if (cycle_dfs(v, color, parent)) { return true; }
			}
			else if (color[v] == 1) { return true; }
		}
		color[u] = 2; return false;
	}
	bool find_cycle() {
		vector<int> color(n, 0), parent(n, -1);
		for (int v = 0; v < n; v++)
			if (cycle_dfs(v, color, parent)) { return true; }
		return false;
	}

	void dfs(int u, vector<int> &visited, vector<char> &ans) {
		visited[u] = true;
		for (auto x : nodes[u].edges) {
			int v = x.v;
			if (!visited[v]) { dfs(v, visited, ans); }
		}
		ans.push_back(u + 'A');
	}
	vector<char> topological_sort() {
		vector<int> visited(n, false);
		vector<char> ans;
		for (int i = 0; i < n; ++i)
			if (!visited[i]) { dfs(i, visited, ans); }
		reverse(ans.begin(), ans.end());
		return move(ans);
	}
};

int main() {
	graph g(5);
	for (int i = 0; i < 5; i++) {
		char a, b, c; cin >> a >> b >> c;
		if (b == '<') { g.add_edge(a - 'A', c - 'A'); }
		else { g.add_edge(c - 'A', a - 'A'); }
	}
	bool b = g.find_cycle();
	if (b) { cout << "impossible" << endl; }
	else { 
		vector<char> ans = g.topological_sort();
		for (auto &x : ans) { cout << x; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}
