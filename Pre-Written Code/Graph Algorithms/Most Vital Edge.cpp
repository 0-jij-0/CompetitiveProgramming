#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct Edge {
	int u = 0, v = 0, w = 0;
	Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<Edge> edges; int m = 0;

	Graph(int _n) : nodes(_n), n(_n) {}

	void addEdge(int u, int v, int w) {
		nodes[u].emplace_back(m++);
		nodes[v].emplace_back(m++);
		edges.emplace_back(u, v, w);
		edges.emplace_back(v, u, w);
	}

	vector<ll> dijkstra(int s, vector<int>& parent) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> vis(n, false);

		while (!pq.empty()) {
			int cur = pq.top().second; pq.pop();
			if (vis[cur]) { continue; }

			vis[cur] = true; for (auto& x : nodes[cur]) {
				Edge& e = edges[x];
				ll newD = dist[cur] + e.w;
				if (dist[e.v] > newD) {
					dist[e.v] = newD; parent[e.v] = cur;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
		return dist;
	}

	void dfsO(int cur, const int& ID, vector<ll>& D, vector<int> &O) {
		O[cur] = ID; for (auto& e : nodes[cur])
			if (D[cur] + edges[e].w == D[edges[e].v])
				if(O[edges[e].v] == -1) dfsO(edges[e].v, ID, D, O);
	}

	pair<Edge, ll> mostVitalEdge(int S, int T) {
		vector<int> parent(n);
		vector<ll> SPS = dijkstra(S, parent), SPT = dijkstra(T, parent);

		//Getting the shortest path between s and t
		vector<int> path; path.emplace_back(T);
		while (path.back() != S) path.emplace_back(parent[path.back()]);
		reverse(path.begin(), path.end()); int K = (int)path.size();

		vector<int> L(n, -1);
		vector<vector<int>> LNodes(K);
		for (int i = 0; i < K; i++) L[path[i]] = i;
		for (int i = 0; i < K; i++) 
			for (auto& x : nodes[path[i]]) {
				Edge& e = edges[x];
				if (SPS[e.u] + e.w == SPS[e.v])
					if (i == K || e.v != path[i + 1])
						dfsO(e.v, i, SPS, L);
			}
		
		for (int i = 0; i < n; i++) 
			if (L[i] != -1)	LNodes[L[i]].push_back(i);

		vector<ll> key(n, INF);
		set<pair<ll, int>> H;
		for (int i = 0; i < n; i++)
			H.insert({ INF, i });

		ll res = -1; int resEdge = -1;
		for (int i = 0; i < K - 1; i++) {
			for (auto& x : LNodes[i]) H.erase({ key[x], x });

			for (auto& cur : LNodes[i]) for (auto& x : nodes[cur]) {
				Edge& e = edges[x];
				ll newK = SPS[e.u] + e.w + SPT[e.v];
				if (e.u != path[i] || e.v != path[i + 1])
					if (L[e.u] < L[e.v] && newK < key[e.v]) {
						H.erase({ key[e.v], e.v });
						H.insert({ key[e.v] = newK, e.v });
					}
			}

			ll curMin = H.begin()->first;
			if (curMin == INF) { continue; }

			if (curMin > res) { res = curMin; resEdge = i; }
		}

		if (res == -1) { return { { -1, -1, -1 }, -1 }; }
		int A = path[resEdge], B = path[resEdge + 1];
		return { { A, B, SPS[B] - SPS[A] }, res };
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}