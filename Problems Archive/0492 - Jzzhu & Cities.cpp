#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
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
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, ll w) {
		edge e1(u, v, w);
		nodes[u].edges.push_back(e1);
	}

	void dijkstra_sp(int s, vector<ll> &dist) {
		vector<bool> visited(n, false);
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[s] = 0ll; pq.push({ 0, s });

		for (int i = 0; i < n; i++) {
			int cur = pq.top().second; pq.pop();
			while (visited[cur]) { cur = pq.top().second; pq.pop(); }
			visited[cur] = true;
			for (auto &e : nodes[cur].edges)
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
		}
	}
};

vector<ll> dist; vector<pair<int, ll>> r;
ll inf = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m, k; cin >> n >> m >> k; 
	dist.resize(n, inf); r.resize(k); graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v; ll w; cin >> u >> v >> w; u--; v--;
		g.add_edge(u, v, w); g.add_edge(v, u, w);
	}
	for (int i = 0; i < k; i++) {
		cin >> r[i].first >> r[i].second; r[i].first--;
		g.add_edge(0, r[i].first, r[i].second);
	}

	g.dijkstra_sp(0, dist); graph newg(n);
	for (auto &x : g.nodes)
		for (auto &e : x.edges)
			if ((dist[e.u] + e.w) == dist[e.v])
				newg.add_edge(e.u, e.v, e.w);

	vector<int> in_deg(n, 0);

	for(auto &x : newg.nodes)
		for (auto &e : x.edges)
			in_deg[e.v]++;

	int res = 0;
	for (int i = 0; i < k; i++)
		if (dist[r[i].first] != r[i].second) { res++; }
		else if (in_deg[r[i].first] > 1) { res++; in_deg[r[i].first]--; }

	cout << res << endl;
	cin.ignore(2); return 0;
}