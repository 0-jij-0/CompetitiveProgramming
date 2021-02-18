#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef int ll;
const ll INF = 1 << 30;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct node { vector<edge> edges; };

struct pqNode {
	ll w = 0, last = 0; int u = 0; pqNode() {}
	pqNode(ll c, ll l, int _u) : w(c), last(l), u(_u) {}
	bool operator < (const pqNode& rhs) const { return w > rhs.w; }
};

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n), nodes(_n) {}

	void add_edge(int &u, int &v, ll &w) {
		nodes[u].edges.emplace_back(u, v, w);
		nodes[v].edges.emplace_back(v, u, w);
	}

	vector<ll> dijkstra(int s) {
		vector<ll> dist(n, INF); dist[s] = 0ll; priority_queue<pqNode> pq;
		pq.push(pqNode(0, 0, s)); vector<int> vis(n, false);

		while (!pq.empty()) {
			pqNode curN = pq.top(); pq.pop();
			bool b = curN.last != 0; int cur = curN.u;
			if (!b && vis[cur]) { continue; }

			if(!b) vis[cur] = true;
			for (edge& e : nodes[cur].edges) {
				if (!b) { pq.push(pqNode(curN.w, e.w, e.v)); continue; }
				ll w = (curN.last + e.w); w = curN.w + w * w;
				if (dist[e.v] > w) { pq.push(pqNode(dist[e.v] = w, 0, e.v)); }
			}
		}
		return move(dist);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int u, v, w;  cin >> u >> v >> w;
		u--; v--; g.add_edge(u, v, w);
	}
	vector<int> d = g.dijkstra(0);
	for (auto& x : d) cout << (x == INF ? -1 : x) << ' '; 
	cout << '\n'; cin.ignore(2); return 0;
}