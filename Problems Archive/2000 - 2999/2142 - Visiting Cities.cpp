#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <set>
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
	graph(int _n) : n(_n) { nodes[0].resize(_n); nodes[1].resize(_n); }

	void add_edge(int u, int v, ll w) {
		nodes[0][u].emplace_back(m++);
		edges.emplace_back(u, v, w);
		nodes[1][v].emplace_back(m++);
		edges.emplace_back(v, u, w);
	}

	vector<ll> dijkstra(int s, bool rev = false) {
		vector<ll> dist(n, INF); dist[s] = 0ll;
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		pq.push({ 0, s }); vector<bool> visited(n, false);

		while (!pq.empty()) {
			if (visited[pq.top().second]) { pq.pop(); continue; }
			int cur = pq.top().second; pq.pop(); visited[cur] = true;
			for (auto& x : nodes[rev][cur]) {
				edge& e = edges[x];
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
			}
		}
		return dist;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		g.add_edge(--a, --b, c);
	}

	vector<ll> DT = g.dijkstra(n - 1, true), DS = g.dijkstra(0);
	vector<vector<edge>> spEdges(n); 
	for (int i = 0; i < g.m; i += 2) {
		edge& e = g.edges[i];
		if (DS[e.u] + e.w + DT[e.v] == DS[n - 1]) 
			spEdges[e.u].push_back(e);
	}

	vector<int> nodes(n); iota(nodes.begin(), nodes.end(), 0);
	auto comp = [&](const int& i, const int& j) { return DS[i] < DS[j]; };
	sort(nodes.begin(), nodes.end(), comp);

	set<int> jumpNodes;
	int last = 0; vector<int> isVital(n, false);
	isVital.front() = isVital.back() = true;
	for (int j = 0; j < n && DS[nodes[j]] < DS[n - 1]; j++) {
		if (DS[nodes[j]] != DS[nodes[last]]) 
			while (last != j) jumpNodes.erase(nodes[last++]);

		if (jumpNodes.size() == 1 && jumpNodes.count(nodes[j])) isVital[nodes[j]] = true;
		for (edge& e : spEdges[nodes[j]]) jumpNodes.insert(e.v);
	}

	cout << count(isVital.begin(), isVital.end(), 1) << '\n';
	for (int i = 0; i < n; i++)
		if (isVital[i]) cout << i + 1 << ' '; cout << '\n';
}