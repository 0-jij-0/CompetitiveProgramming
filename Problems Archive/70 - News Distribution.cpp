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

int n, m;
vector<node> graph;
vector<int> visited;

void get_edge(int a, int b) {
	edge e1(a, b), e2(b, a);
	graph[a].edges.push_back(e1);
	graph[b].edges.push_back(e2);
}

int bfs(int u, int t) {
	
	queue<int> q; q.push(u);
	visited[u] = t;
	int count = 1;

	while (!q.empty()) {
		int f = q.front(); q.pop(); 
		node &n = graph[f];
		for (auto x : n.edges) {
			int dest = x.b;
			if (visited[dest] == 0) {
				q.push(dest); count++;
				visited[dest] = t;
			}
		}
	}
	return count;
}

int main() {
	cin >> n >> m;
	graph.resize(n+1);

	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		int prev = -1;
		for (int j = 0; j < k; j++) { 
			int a; cin >> a;
			if (prev == -1) { prev = a; continue; }
			get_edge(prev, a); prev = a;
		}
	}

	visited.resize(n + 1, 0);
	vector<int> count; count.resize(n + 1);
	int t = 1;
	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) { count[t] = bfs(i, t); t++; }
	}
	for (int i = 1; i <= n; i++) {
		cout << count[visited[i]];
		if (i != n) { cout << " "; }
		else { cout << endl; }
	}

	return 0;
}

