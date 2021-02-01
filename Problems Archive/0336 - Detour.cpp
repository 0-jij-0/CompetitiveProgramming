#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

struct edge {
	int u, v; long long w;
	edge() {}
	edge(int _u, int _v, long long _w = 0ll) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
};

struct node {
	int id; vector<edge> edges;
};

struct comp {
	bool operator ()(const pair<long long, int> &p1, const pair<long long, int> &p2) {
		return p1.first > p2.first;
	}
};

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	vector<int> parent;
	vector<long long> dist;
	int n;

	graph(int _n) :n(_n) {
		nodes.resize(n); parent.resize(n, -1); dist.resize(n, (long long)INT_MAX);
	}

	void add_edge(int u, int v, long long w = 0) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1);
	}

	void dfs(int u, int v) {
		vector<int> p(n, -1);
		stack<int> s; s.push(u);
		vector<bool> visited(n, false);
		visited[u] = true; bool b = false;

		while (!s.empty()) {
			int f = s.top(); s.pop();
			if (f == v) { b = true; break; }
			node &n = nodes[f];
			for (int i = 0; i < (int)n.edges.size(); i++) {
				int dest = n.edges[i].v;
				if (dest == parent[f]) { continue; }
				if (!visited[dest]) {
					p[dest] = f;
					s.push(dest); visited[dest] = 1;
				}
			}
		}
		if (!b) { cout << "impossible" << endl; return; }
		vector<int> path;
		while (v != u) { path.push_back(v); v = p[v]; }
		path.push_back(u);
		cout << (int)path.size() << ' ';
		for (int i = (int)path.size() - 1; i >= 0; i--) { 
			cout << path[i];
			if (i != 0) { cout << ' '; }
			else { cout << endl; }
		}	
	}

	void shortestPath(int s) {
		vector<bool> visited(n, false);
		priority_queue<pair<long long, int>, vector<pair<long long, int>>, comp> pq;
		dist[s] = 0ll; pq.push({ 0, s });

		for(int i = 0; i < n; i++) {
			int cur = pq.top().second; pq.pop();
			while (visited[cur]) { cur = pq.top().second; pq.pop(); }
			visited[cur] = true;
			for (auto &e : nodes[cur].edges) {
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					parent[e.v] = e.u;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
	}
};

int main() {
	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; long long d; 
		cin >> a >> b >> d;
		g.add_edge(a, b, d);
	}
	g.shortestPath(1); g.dfs(0, 1);

	cin.ignore(2); return 0;
}