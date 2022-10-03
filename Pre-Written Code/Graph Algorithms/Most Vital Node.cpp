#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
};

struct graph {
	vector<vector<int>> nodes[2]; int n;
	vector<edge> edges; int m = 0;
	vector<int> O; vector<vector<int>> ONodes;

	graph(int _n) : n(_n) { nodes[0].resize(n); nodes[1].resize(n); }

	void add_edge(int u, int v, int w) {
		nodes[0][u].emplace_back(m++);
		edges.emplace_back(u, v, w);
		nodes[1][v].emplace_back(m++);
		edges.emplace_back(v, u, w);
	}

	vector<ll> dijkstra(int s, vector<int>& parent, bool rev = false) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> visited(n, false);

		while (!pq.empty()) {
			if (visited[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); visited[cur] = true;
			for (int& x : nodes[rev][cur]) {
				edge& e = edges[x]; ll newD = dist[cur] + e.w;
				if (dist[e.v] > newD) {
					dist[e.v] = newD; parent[e.v] = cur;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
		return dist;
	}

	void dfsO(int cur, const int& id, vector<ll>& d) {
		O[cur] = id; for (auto& x : nodes[0][cur]) {
			edge& e = edges[x];
			if (d[cur] + e.w == d[e.v] && O[edges[x].v] == -1)
				dfsO(edges[x].v, id, d);
		}
	}

	pair<int, ll> mostVitalNode(int s, int t) {
		vector<int> SPT(n, -1);
		vector<ll> SGT = dijkstra(t, SPT, true), SGS = dijkstra(s, SPT);

		//Getting the shortest path between s and t
		vector<int> path; path.emplace_back(t);
		while (path.back() != s) path.emplace_back(SPT[path.back()]);
		reverse(path.begin(), path.end()); int K = (int)path.size();

		//Finding for each node to what O-component it belongs
		O.resize(n, -1); ONodes.resize(K);
		for (int i = 0; i < K; i++) O[path[i]] = i;
		for (int i = 0; i < K; i++) {
			for (auto& x : nodes[0][path[i]]) {
				edge& e = edges[x]; if (i != K - 1 && e.v == path[i + 1]) continue;
				if (O[e.v] == -1 && SGS[path[i]] + e.w == SGS[e.v]) dfsO(e.v, i, SGS);
			}
		}

		//Generating the O components
		for (int i = 0; i < n; i++) if (O[i] != -1)
			if (i != path[O[i]]) ONodes[O[i]].push_back(i);

		//Getting Edges from Ui to Oi and from Oi to Oi
		vector<vector<int>> EUO(K), EOO(n);
		for (int i = 0; i < m; i += 2) {
			edge& e = edges[i];	if (e.u == SPT[e.v] || O[e.u] == -1) { continue; }
			if (O[e.u] < O[e.v] && e.v != path[O[e.v]]) { EUO[O[e.v]].push_back(i); continue; }
			if (O[e.u] == O[e.v] && e.u != path[O[e.u]] && e.v != path[O[e.v]]) EOO[e.u].push_back(i);
		}

		//Giving nodes of O[0] respective distances
		vector<ll> PGD(n, INF); PGD[s] = 0;
		for (auto& x : ONodes[0]) PGD[x] = SGS[x];

		//Initializing the set of nodes in Di
		set<pair<ll, int>> H; vector<ll> key(n, INF);
		for (int i = 0; i < n; i++) if (O[i]) H.insert({ INF, i });

		ll res = -1; int resNode = -1;
		for (int i = 1; i < K - 1; i++) {

			//Removing nodes that are no longer in the D region
			H.erase({ key[path[i]], path[i] });
			for (auto& x : ONodes[i]) { H.erase({ key[x], x }); }

			//Finding shortest path to O[i] nodes using only current U and O regions
			priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
			for (auto& x : EUO[i]) { edge& e = edges[x]; pq.push({ SGS[e.u] + e.w, e.v }); }
			while (!pq.empty()) {
				int cur = pq.top().second; ll W = pq.top().first; pq.pop();

				if (PGD[cur] <= W) { continue; }
				PGD[cur] = W; for (int& x : EOO[cur])
					pq.push({ W + edges[x].w, edges[x].v });
			}

			for (auto& y : ONodes[i]) for (auto& x : nodes[0][y]) {
				edge& e = edges[x]; if (!H.count({ key[e.v], e.v })) continue;
				ll newK = PGD[y] + e.w + SGT[e.v]; if (newK >= key[e.v]) continue;
				H.erase({ key[e.v], e.v }); H.insert({ key[e.v] = newK, e.v });
			}

			ONodes[i - 1].push_back(path[i - 1]);
			for (auto& y : ONodes[i - 1]) for (auto& x : nodes[0][y]) {
				edge& e = edges[x]; if (!H.count({ key[e.v], e.v })) continue;
				ll newK = SGS[y] + e.w + SGT[e.v]; if (newK >= key[e.v]) continue;
				H.erase({ key[e.v], e.v }); H.insert({ key[e.v] = newK, e.v });
			}

			ll curMin = H.begin()->first;
			if (curMin == INF) { continue; }
			if (curMin > res) { res = curMin; resNode = i; }
		}

		if (res == -1) { return { -1, -1 }; }
		return { path[resNode], res };
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}