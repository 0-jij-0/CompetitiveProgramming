#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

ll K;

struct pqT { 
	ll W; int cur, col;
	pqT(ll _W, int _cur, int _col) : W(_W), cur(_cur), col(_col) {}
	bool operator < (const pqT& rhs) const { return W > rhs.W; }
};

struct edge {
	int u, v, col; ll w; edge() {}
	edge(int _u, int _v, int _c, ll _w) :
		u(_u), v(_v), col(_c), w(_w) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int u, int v, int c, ll w) {
		nodes[u].edges.emplace_back(u, v, c, w);
		nodes[v].edges.emplace_back(v, u, c, w);
	}

	bool dijkstraSingleColor(const int &c) {
		vector<ll> dist(n, INF); dist[0] = 0ll;
		priority_queue<pqT> pq; pq.push(pqT(0, 0, 0));
		vector<bool> vis(n, 0);

		while (!pq.empty()) {
			if (vis[pq.top().cur]) { pq.pop(); continue; }

			int cur = pq.top().cur; pq.pop();
			for (edge& e : nodes[cur].edges) if(e.col == c) {
				ll newW = dist[cur] + e.w;
				if (dist[e.v] > newW) {
					dist[e.v] = newW;
					pq.push(pqT(newW, e.v, 0));
				}
			}
		}

		return dist.back() <= K;
	}

	bool dijkstra(const ll &C) {
		vector<vector<ll>> dist(n, vector<ll>(5, INF)); dist[0][0] = 0ll;
		priority_queue<pqT> pq; pq.push(pqT(0, 0, 0)); 
		vector<vector<bool>> vis(n, vector<bool>(5, false));

		while (!pq.empty()) {
			if (vis[pq.top().cur][pq.top().col]) { pq.pop(); continue; }

			int cur = pq.top().cur, col = pq.top().col; pq.pop();
			for (edge& e : nodes[cur].edges) {
				ll newW = dist[cur][col] + e.w + C * (col != e.col);
				if (dist[e.v][e.col] > newW) {
					dist[e.v][e.col] = newW;
					pq.push(pqT(newW, e.v, e.col));
				}
			}
		}
		
		return *min_element(dist.back().begin(), dist.back().end()) <= K;
	}

	string findMinC() {
		if (dijkstraSingleColor(0)) return "relaxing";

		ll l = 0, r = 1ll << 40;
		while (l != r) {
			ll mid = (l + r + 1) >> 1;
			dijkstra(mid) ? l = mid : r = mid - 1;
		}

		return l ? to_string(l) : "impossible";
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m >> K; graph g(n);
		for (int i = 0; i < m; i++) {
			int u, v, w; char c; cin >> u >> v >> w >> c;
			u--; v--; g.add_edge(u, v, c - 'a', w);
		}
		cout << g.findMinC() << '\n';
	}
	cin.ignore(2); return 0;
}