#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node {
	vector<edge> edges;
	node() {}
};

vector<node> graph;
vector<int> connected;

void add_edge(int u, int v) {
	edge e1(u, v); edge e2(v, u);
	graph[u].edges.push_back(e1);
	graph[v].edges.push_back(e2);
}

bool dfs(int u, int t) {
	stack<int> s; s.push(u);
	connected[u] = t;
	bool cycle = false;
	bool edges = true;
	int nodes = 0;

	while (!s.empty()) {
		int f = s.top(); s.pop(); nodes++;
		node *n = &graph[f];
		unsigned int size = n->edges.size();
		if (size != 2) { edges = false; }
		for (unsigned int i = 0; i < size; i++) {
			int dest = n->edges[i].v;
			if (nodes >= 3 && dest == u) { cycle = edges; }
			if (connected[dest] == 0) {
				if (!s.empty() && s.top() == u) { cycle = false; }
				s.push(dest);
				connected[dest] = t;
			}
		}
	}
	return cycle;
}

int cyc_num(int n) {
	int count = 0; int t = 1;
	for (int i = 1; i <= n; i++) {
		if (connected[i] != 0) { continue; }
		bool b = dfs(i, t); t++;
		if (b) { count++; }
	}
	return count;
}

int main() {
	int n, m; cin >> n >> m;
	graph.resize(n + 1); connected.resize(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		add_edge(u, v);
	}
	cout << cyc_num(n) << endl;
	cin.ignore(2); return 0;
}