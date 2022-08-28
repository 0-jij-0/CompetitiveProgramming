#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
	int u, v; bool w; Edge() {}
	Edge(int _u, int _v, bool _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<Edge>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, bool w) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	void bfs01(int src, vector<bool> &vis, vector<int> &dist) {
		deque<int> L; L.push_back(src); dist[src] = 0;
		while (!L.empty()) {
			if (vis[L.front()]) { L.pop_front(); continue; }
			int cur = L.front(); L.pop_front(); vis[cur] = true;

			for (Edge &e : nodes[cur]) if(!vis[e.v]) {
				dist[e.v] = min(dist[e.v], dist[cur] + e.w);
				e.w ? L.push_back(e.v) : L.push_front(e.v);
			}
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}