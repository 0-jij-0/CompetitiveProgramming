#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

ll shortestPath, X;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, ll w) {
		edge e1(u, v, w), e2(v, u, w);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}
	ll dijkstra_sp() {
		vector<bool> visited(n, false);	vector<ll> dist(n, 1ll << 60);
		priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[0] = 0ll; pq.push({ 0, 0 });

		for (int i = 0; i < n; i++) {
			int cur = pq.top().second; pq.pop();
			while (visited[cur]) { cur = pq.top().second; pq.pop(); }
			visited[cur] = true; if (cur == n - 1) { return dist[cur]; }
			for (auto &e : nodes[cur].edges) {
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
		return 0;
	}
	bool check(ll w) {
		vector<bool> visited(n, false);	vector<ll> dist(n, 1ll << 60);
		priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[0] = 0ll; pq.push({ 0, 0 });

		for (int i = 0; i < n; i++) {
			if (pq.empty()) { break; }
			int cur = pq.top().second; pq.pop();
			while (!pq.empty() && visited[cur]) { cur = pq.top().second; pq.pop(); }
			if (visited[cur]) { break; }
			visited[cur] = true; if (cur == n - 1) { return 100 * dist[cur] <= (100 + X)*shortestPath; }
			for (auto &e : nodes[cur].edges) {
				if (e.w > w) { continue; }
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
		return false;
	}
};

ll findMin(graph &g) {
	ll l = 1, r = 1ll << 30;
	while (l != r) {
		ll mid = (l + r) >> 1;
		bool b = g.check(mid);
		b ? r = mid : l = mid + 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m >> X; graph g(n);
	for (int i = 0; i < m; i++) {
		int c1, c2; ll w; cin >> c1 >> c2 >> w;
		c1--; c2--; g.add_edge(c1, c2, w);
	}
	shortestPath = g.dijkstra_sp();
	cout << findMin(g) << endl;
	cin.ignore(2); return 0;
}