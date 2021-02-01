#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int inf = 1000000;

struct edge {
	int u, v, w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes[2]; int n;
	vector<edge> edges; int m;
	graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void add_edge(int u, int v, int w) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[0][u].edges.push_back(e1);
		nodes[1][v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	set<int> bfs(int u, bool b) {
		vector<int> visited(n, false);
		queue<int> q; q.push(u); set<int> s;
		visited[u] = true;
		while (!q.empty()) {
			int f = q.front(); q.pop();
			s.insert(f); node& n = nodes[b][f];
			for (auto &x : n.edges) {
				int dest = x.v;
				if (visited[dest] == false) {
					q.push(dest); visited[dest] = true;
				}
			}
		}
		return move(s);
	}

	graph reach_graph(int src, int dst) {
		set<int> s1 = bfs(src, 0), s2 = bfs(dst, 1), s3;
		for (auto &x : s1)
			if (s2.count(x)) 
				s3.insert(x);
		graph g(n);
		for (auto &e : edges)
			if (s3.count(e.u) && s3.count(e.v)) 
				g.add_edge(e.u, e.v, e.w);
		return move(g);
	}

	bool bellman_ford() {
		vector<int> d(n, inf), parent(n, -1); 
		int x; d[0] = 0;
		for (int i = 0; i < n; ++i) {
			x = -1;
			for (edge &e : edges) {
				int dis = d[e.u] + e.w;
				if (dis < min(d[e.v], 100)) {
					d[e.v] = dis; parent[e.v] = e.u; x = e.v;
				}
			}
		}
		return (x == -1) ? d[n - 1] < 100 : true;
	}
};

vector<int> v;

int main() {
	int n; cin >> n;
	while (n != -1) {
		graph g(n); v.clear(); v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i]; v[i] = -v[i];
			int m; cin >> m; set<int> s;
			for (int j = 0; j < m; j++) {
				int a; cin >> a; a--;
				if (i == n - 1) { continue; }
				if (!s.count(a)) { g.add_edge(i, a, 0); }
			}
		}
		for (auto &x : g.edges) { x.w = v[x.v]; }
		graph new_g = g.reach_graph(0, n - 1);
		cout << (new_g.bellman_ford() ? "winnable" : "hopeless") << endl;
		cin >> n;
	}
	cin.ignore(2); return 0;
}