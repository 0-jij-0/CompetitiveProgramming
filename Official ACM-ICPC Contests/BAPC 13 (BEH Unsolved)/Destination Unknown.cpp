#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;
 
int s, g, h; ll eW;
vector<int> dest;
vector<ll> distS, distG, distH;
 
struct edge {
	int u, v; ll w;
	edge(int _u, int _v, ll _w) :u(_u), v(_v), w(_w) {}
};
struct node { vector<edge> edges; };
struct graph {
	int n;
	vector<node> nodes;
 
	graph(int _n) :n(_n) { nodes.resize(n); }
	void add_edge(int u, int v, ll w) {
		nodes[u].edges.push_back(edge(u, v, w));
		nodes[v].edges.push_back(edge(v, u, w));
	}
 
	vector<ll> dijkstra_sp(int ss) {
		vector<ll> dist; dist.resize(n, INF);
		vector<bool> visited(n, false);
		priority_queue <pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		dist[ss] = 0ll; pq.push({ 0, ss });
 
		while(!pq.empty()){
			int cur = pq.top().second; pq.pop();
			while (!pq.empty() && visited[cur]) { cur = pq.top().second; pq.pop(); }
			if (visited[cur]) { break; } visited[cur] = true;
 
			for (auto &e : nodes[cur].edges)
				if (dist[e.v] > dist[cur] + e.w) {
					dist[e.v] = dist[cur] + e.w;
					pq.push({ dist[e.v], e.v });
				}
		}
 
		return dist;
	}
 
	bool check(int t) {
		if (distS[t] == INF) { return false; }
		if (distS[t] == distS[g] + distH[t] + eW) { return true; }
		if (distS[t] == distS[h] + distG[t] + eW) { return true; }
		return false;
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int t; cin >> t;
 
	while (t--) {
		int n, m, d; cin >> n >> m >> d;
		cin >> s >> g >> h; s--; g--; h--;
		graph gg(n); dest.clear(); dest.resize(d);
		for (int i = 0; i < m; i++) {
			int u, v; ll dis; 
			cin >> u >> v >> dis; u--; v--;
			gg.add_edge(u, v, dis);
			if (u == g && v == h) { eW = dis; }
			if (u == h && v == g) { eW = dis; }
		}
		for (auto &x : dest) { cin >> x; x--; }
		sort(dest.begin(), dest.end());
 
		distS.clear(); distS = gg.dijkstra_sp(s);
		distG.clear(); distG = gg.dijkstra_sp(g);
		distH.clear(); distH = gg.dijkstra_sp(h);
 
		for (int x : dest) {
			if (gg.check(x)) { cout << x + 1 << ' '; }
		}
		cout << '\n';
	}
}