#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

vector<ll> SP;

struct PQObj {
	int cur, s; ll w; PQObj() {}
	PQObj(int _c, int _s, ll _w) : cur(_c), s(_s), w(_w) {}
	bool operator < (const PQObj& rhs) const {
		if (w != rhs.w) return w > rhs.w;
		return s > rhs.s;
	}
};

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

	vector<int> candidates() {
		vector<bool> visited(n, false);
		vector<ll> dist(n, INF);
		priority_queue<PQObj> pq;
		vector<int> valid(n, 1);

		ll targetMin = *min_element(SP.begin(), SP.end());
		for (int i = 0; i < n; i++) {
			ll minW = 1e12;
			for (auto& e : nodes[i].edges) {
				if (e.w < minW) { minW = e.w; }
			}
			if (minW != targetMin || SP[i] != minW * 2) { valid[i] = 0; }
			else { pq.push(PQObj(i, i, 0)); }
		}

		while (!pq.empty()) {
			PQObj curP = pq.top(); pq.pop();
			if (!valid[curP.s] || visited[curP.cur]) { continue; }
			if (curP.w && curP.w != SP[curP.cur]) { valid[curP.s] = 0; continue; }
			visited[curP.cur] = true;

			int& cur = curP.cur, & s = curP.s; ll& w = curP.w;
			for (edge& e : nodes[cur].edges) {
				if (dist[e.v] > w + e.w) {
					dist[e.v] = w + e.w;
					pq.push(PQObj(e.v, s, w + e.w));
				}
			}
		}
		return move(valid);
	}

	bool dijkstra_sp(int s) {
		vector<bool> visited(n, false);
		vector<ll> dist(n, INF);
		priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[s] = 0ll; pq.push({ 0, s });

		while (!pq.empty()) {
			int cur = pq.top().second; pq.pop();
			if (visited[cur]) { continue; }
			if (cur != s && dist[cur] != SP[cur]) { return false; }
			visited[cur] = true;

			for (auto& e : nodes[cur].edges) {
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
		return true;
	}
};

int main() {
	freopen("hide.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	graph g(n); SP.resize(n);
	for (auto& x : SP) { cin >> x; }
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, w);
	}
	vector<int> valid = g.candidates();

	int res = -1; for (int i = 0; i < n; i++) if (valid[i])
		if (g.dijkstra_sp(i)) { res = i + 1; break; }

	cout << res << '\n'; cin.ignore(2); return 0;
}