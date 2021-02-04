#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, ll w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	int primMST(int s, vector<int> &parent) {
		vector<bool> visited(n, false); vector<ll> dist(n, 1ll << 40);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[s] = 0ll; pq.push({ 0, s }); int res = 0;
		for (int i = 0; i < n; i++) {
			int cur = pq.top().second; pq.pop();
			while (visited[cur]) { cur = pq.top().second; pq.pop(); }
			visited[cur] = true; res += dist[cur];
			for (edge &e : nodes[cur].edges)
				if (dist[e.v] > e.w) {
					dist[e.v] = e.w; parent[e.v] = e.u;	pq.push({ dist[e.v], e.v });
				}
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin.ignore(2); return 0;
}