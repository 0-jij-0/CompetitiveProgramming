#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 40;

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

	int primMST(int s, vector<int> &par) {
		vector<bool> vis(n, false); vector<ll> dist(n, INF);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[s] = 0ll; pq.push({ 0, s }); int res = 0;

		for (int i = 0; i < n; i++) {
			int cur = pq.top().second; pq.pop();
			while (vis[cur]) { cur = pq.top().second; pq.pop(); }

			vis[cur] = true; res += dist[cur];
			for (Edge &e : nodes[cur])
				if (dist[e.v] > e.w) {
					par[e.v] = e.u;	
					pq.push({ dist[e.v] = e.w, e.v });
				}
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}