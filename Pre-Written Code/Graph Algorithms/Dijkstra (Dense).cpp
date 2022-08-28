#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;

struct Edge {
	int u, v; ll w; Edge() {}
	Edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<Edge>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, ll w) {
		nodes[u].emplace_back(u, v, w);
		nodes[v].emplace_back(v, u, w);
	}

	void dijkstra(int s, vector<ll> &dist, vector<int> &par) {
		vector<bool> vis(n, false); dist[s] = 0; int cur = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				if (vis[cur] || (!vis[j] && dist[j] < dist[cur])) cur = j;

			vis[cur] = true;
			for (Edge &e : nodes[cur])
				if (dist[e.v] > dist[cur] + e.w)
					dist[e.v] = dist[par[e.v] = cur] + e.w;
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}