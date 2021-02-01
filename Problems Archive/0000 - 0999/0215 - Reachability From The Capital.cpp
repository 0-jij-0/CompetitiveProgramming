#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int a, b;
	edge() {}
	edge(int _a, int _b) :
		a(_a), b(_b) {}
};

struct node {
	int idx;
	vector<edge> edges;
};

int n, m, s;
vector<node> graph;
vector<int> visited;

void get_edge(int a, int b) {
	edge e1(a, b);
	graph[a].edges.push_back(e1);
}

void bfs(int u, int t) {

	queue<int> q; q.push(u);
	visited[u] = t;
	int count = 1;

	while (!q.empty()) {
		int f = q.front(); q.pop();
		node *n = &graph[f];
		for (unsigned int i = 0; i < n->edges.size(); i++) {
			int dest = n->edges[i].b;
			if (visited[dest] == -1) {
				q.push(dest); count++;
				visited[dest] = t;
			}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	graph.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		get_edge(u, v);
	}

	visited.resize(n + 1, -1);
	bfs(s, 0); int t = 1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == -1) { bfs(i, t); t++; }
	}
	cout << t - 1 << endl;
	cin.ignore(2); return 0;
}