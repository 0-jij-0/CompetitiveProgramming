#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct Edge {
	int u, v, w; Edge() {}
	Edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, int w = 0) {
		nodes[u].emplace_back(m++);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, w);
		edges.emplace_back(v, u, w);
	}
	
	//tin[u] = discovery time of u
	//low[u] = lowest discovery time of a reachable node
	void bridgeDFS(int cur, int p, vector<bool> &vis, vector<int> &low, vector<int> &tin, int &timer) {
		vis[cur] = true; tin[cur] = low[cur] = timer++;
		for (auto &x : nodes[cur]) {
			Edge &e = edges[x];	if (e.v == p) { continue; }
			if (vis[e.v]) { low[cur] = min(low[cur], tin[e.v]); continue; }

			bridgeDFS(e.v, cur, vis, low, tin, timer);
			low[cur] = min(low[cur], low[e.v]);
			if (low[e.v] > tin[cur]); //isBridge(x);
		}
	}

	void artPointDFS(int cur, int p, vector<bool> &vis, vector<int> &low, vector<int> &tin, int &timer) {
		vis[cur] = true; tin[cur] = low[cur] = timer++; int c = 0;
		for (auto &x : nodes[cur]) {
			Edge &e = edges[x];	if (e.v == p) { continue; }
			if (vis[e.v]) { low[cur] = min(low[cur], tin[e.v]); continue; }

			artPointDFS(e.v, cur, vis, low, tin, timer);
			low[cur] = min(low[cur], low[e.v]); c++;
			if (p != -1 && low[e.v] >= tin[cur]); //isArtPoint(cur);		Might run this for node cur multiple times (once for each child)
		}
		if (p == -1 && c > 1); //isArtPoint(cur);
	}

	void findBridges() {
		int timer = 0; vector<bool> vis(n, false);
		vector<int> low(n, -1), tin(n, -1);
		for (int i = 0; i < n; i++)	if (!vis[i])
			bridgeDFS(i, -1, vis, low, tin, timer);
	}
	void findArtPoints() {
		int timer = 0; vector<bool> vis(n, false);
		vector<int> low(n, -1), tin(n, -1);
		for (int i = 0; i < n; i++)	if (!vis[i])
			artPointDFS(i, -1, vis, low, tin, timer);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}