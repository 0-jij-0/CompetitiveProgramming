#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

struct edge {
	int u, v, s; ld w; edge() {}
	edge(int _u, int _v, ld _w, int _s) :
		u(_u), v(_v), w(_w), s(_s) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, ld w, int s1, int s2) {
		edge e1(u, v, w, s1), e2(v, u, w, s2);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void dijkstra_sp(int src, int s, vector<vector<ld>> &dist) {
		vector<vector<bool>> visited(n, vector<bool>(5700, false));
		priority_queue<pair<pair<ld, int>, int>, vector<pair<pair<ld, int>, int>>, greater<pair<pair<ld, int>, int>>> pq;
		dist[src][s] = 0ll; pq.push({ { 0, s }, src });
		vector<int> stamina(n, 1 << 30);

		while (!pq.empty()) {
			int cur = pq.top().second, st = pq.top().first.second; pq.pop();
			if (visited[cur][st]) { continue; }
			if (st > stamina[cur]) { continue; }
			stamina[cur] = st; visited[cur][st] = true;
			for (auto &e : nodes[cur].edges)
				if (st + e.s >= 5700) { continue; }
				else if (dist[e.v][st + e.s] > dist[cur][st] + e.w) {
					dist[e.v][st + e.s] = dist[cur][st] + e.w;
					pq.push({ { dist[e.v][st + e.s], st + e.s }, e.v });
				}
		}
	}
};

vector<string> v;
int h, w, r, s;

int dist(int i1, int i2, int j1, int j2) {
	int dx = i1 - i2, dy = j1 - j2;
	return dx * dx + dy * dy;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> h >> w >> r >> s; v.resize(h);
	for (auto &x : v) { cin >> x; }

	graph g(w * h); int src = 0, dst = 0; bool fD = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!fD && v[i][j] != '.') { dst = i * w + j; fD = true; }
			if (v[i][j] != '.') { src = i * w + j; }
		}
	}
	for (int i1 = 0; i1 < h; i1++)
		for (int j1 = 0; j1 < w; j1++)
			for (int i2 = 0; i2 < h; i2++)
				for (int j2 = 0; j2 < w; j2++) {
					if (i1 == i2 && j1 == j2) { continue; }
					if (v[i1][j1] == '.' || v[i2][j2] == '.') { continue; }
					int d = dist(i1, i2, j1, j2); if (d > r*r) { continue; }
					g.add_edge(i1 * w + j1, i2*w + j2, sqrt(d), v[i2][j2] - '0', v[i1][j1] - '0');
				}

	vector<vector<ld>> dist(w*h, vector<ld>(5700, 1e10));
	g.dijkstra_sp(src, v[src / w][src % w] - '0', dist);
	int req = min(5700, s + 1); ld res = *min_element(dist[dst].begin(), dist[dst].begin() + req);
	if (res > 1e9) { cout << -1 << endl; }
	else { cout << fixed << setprecision(10) << res << endl; }

	cin.ignore(2); return 0;
}