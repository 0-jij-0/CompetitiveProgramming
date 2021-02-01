#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const int INF = 1 << 30;

struct edge {
	int u, v; int w; edge() {}
	edge(int _u, int _v, int _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, int w = 1) {
		nodes[u].edges.emplace_back(u, v, w);
	}

	vector<int> dijkstra(int s) {
		vector<int> dist(n, INF); dist[s] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({ 0, s }); vector<bool> visited(n, false);

		while (!pq.empty()) {
			if (visited[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); visited[cur] = true;
			for (edge& e : nodes[cur].edges)
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
		}
		return move(dist);
	}

	vector<int> dijkstra2(int s, vector<int>& d) {
		vector<vector<int>> dist(2, vector<int>(n, INF));
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		vector<vector<bool>> visited(2, vector<bool>(n, false));

		for (int i = 0; i < n; i++) { pq.push({ d[i], {i, 0} }); dist[0][i] = d[i]; }

		while (!pq.empty()) {
			if (visited[pq.top().second.second][pq.top().second.first]) { pq.pop(); continue; }
			int cur = pq.top().second.first; int state = pq.top().second.second; int r = dist[state][cur];
			pq.pop(); visited[state][cur] = true;
			for (edge& e : nodes[cur].edges) {
				
				if (d[e.v] < d[cur] && dist[state][e.v] > dist[state][cur]) {
					dist[state][e.v] = dist[state][cur];
					pq.push({ dist[state][e.v], {e.v, state} });
					continue;
				}

				if (d[e.v] < d[cur]) { continue; }
				if (!state && dist[1][e.v] > dist[0][cur]) {
					dist[1][e.v] = dist[0][cur];
					pq.push({ dist[1][e.v], { e.v, 1 } });
				}
				
			}
		}
		for (int i = 0; i < n; i++) dist[1][i] = min(dist[0][i], dist[1][i]);
		return move(dist[1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; graph g1(n), g2(n);
		for (int i = 0; i < m; i++) {
			int u, v; cin >> u >> v; u--; v--;
			g1.add_edge(u, v); g2.add_edge(v, u);
		}
		vector<int> d = g1.dijkstra(0);
		vector<int> res = g2.dijkstra2(0, d);

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}