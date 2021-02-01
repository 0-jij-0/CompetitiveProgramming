#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
	int u, v; bool w; edge() {}
	edge(int _u, int _v, bool _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, bool w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	void bfs01(int src, vector<bool> &visited, vector<int> &dist) {
		deque<int> L; L.push_back(src); dist[src] = 0;
		while (!L.empty()) {
			if (visited[L.front()]) { L.pop_front(); continue; }
			int f = L.front(); L.pop_front(); visited[f] = true;

			for (edge &e : nodes[f].edges) {
				if (visited[e.v]) { continue; }
				dist[e.v] = min(dist[e.v], dist[f] + e.w);
				e.w ? L.push_back(e.v) : L.push_front(e.v);
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}