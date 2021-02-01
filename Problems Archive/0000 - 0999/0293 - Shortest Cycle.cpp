#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> v;
vector<int> b;
int n;

struct edge {
	int u, v;
	edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node {
	int id; vector<edge> edges;
};

struct graph {
	vector<node> nodes;
	int n;

	graph(int _n) :n(_n) {
		nodes.resize(n);
	}

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	int bfs(int src, int dest) {
		queue <int> q; q.push(src);
		vector <bool> visited(n, false);
		int dist[120]; dist[src] = 0;
		visited[src] = true;

		while (!q.empty()) {
			int f = q.front(); q.pop();
			if (f == dest) { return dist[f]; }
			node &n = nodes[f];
			for (int i = 0; i < (int)n.edges.size(); i++) {
				int d = n.edges[i].v;
				if (f == src && d == dest) { continue; }
				if (f == dest && d == src) { continue; }
				if (!visited[d]) {
					q.push(d); visited[d] = 1;
					dist[d] = 1 + dist[f];
				}
			}
		}
		return -1;
	}
};

int find_shortest_cycle() {
	b.resize(64);
	for (auto &x : v) {
		long long mask = 1; int i = 0;
		while (mask <= x) {
			if (mask & x) {
				b[i]++; if (b[i] > 2) { return 3; }
			}
			mask <<= 1; i++;
		}
	}
	graph g(n);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] & v[j]) 
				g.add_edge(i, j);
	int res = 1000;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (v[i] & v[j]) {
				int a = g.bfs(i, j);
				if (a != -1)
					res = min(res, a + 1);
			}
	if (res == 1000) { return -1; }
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { 
		long long x; cin >> x; 
		if (x) { v.push_back(x); }
	}
	n = (int)v.size();
	cout << find_shortest_cycle() << endl;
	cin.ignore(2); return 0;
}