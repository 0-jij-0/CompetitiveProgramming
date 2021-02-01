#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node {
	int id, dist;
	vector<edge> edges;
	node() {}
	bool operator <(const node &rhs) {
		return dist < rhs.dist;
	}
};

vector<node> graph;
vector<bool> connected;

void getedge(int u, int v) {
	edge e1(u, v), e2(v, u);
	graph[u].edges.push_back(e1);
	graph[v].edges.push_back(e2);
}

void bfs(int u) {
	queue<int> q; q.push(u); 
	connected[u] = true; graph[u].dist = 1;

	while (!q.empty()) {
		int f = q.front(); q.pop();
		node *n = &graph[f];
		unsigned int size = n->edges.size();
		for (unsigned int i = 0; i < size; i++) {
			int dest = n->edges[i].v;
			if (connected[dest] == 0) {
				graph[dest].dist = (n->dist + 1) % 2;
				q.push(dest);
				connected[dest] = true;
			}
		}
	}
}

void print_cover(int n) {
	connected.resize(n + 1, false);
	bfs(1); graph.erase(graph.begin());
	sort(graph.begin(), graph.end());
	node x; x.dist = 1;
	int zeros = lower_bound(graph.begin(), graph.end(), x) - graph.begin();
	int ones = n - zeros;
	int i = (zeros < ones) ? 0 : zeros;
	int j = (zeros < ones) ? zeros : n;
	cout << j - i << endl;
	for (int k = i; k < j; k++) {
		cout << graph[k].id;
		if (k + 1 != j) { cout << " "; }
		else { cout << endl; return; }
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		graph.clear(); connected.clear();
		int n, m; cin >> n >> m;
		graph.resize(n + 1); 
		for (int j = 1; j <= n; j++) { graph[j].id = j; }
		for (int j = 0; j < m; j++) {
			int u, v; cin >> u >> v; getedge(u, v);
		}
		print_cover(n);
	}
	cin.ignore(2); return 0;
}