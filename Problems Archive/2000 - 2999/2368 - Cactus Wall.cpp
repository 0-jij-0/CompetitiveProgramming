#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int u, v; bool w; Edge() {}
	Edge(int _u, int _v, bool _w) :
		u(_u), v(_v), w(_w) {}
};

struct Graph {
	vector<vector<Edge>> nodes; int n;
	Graph(int _n) : n(_n), nodes(_n) {}

	void addEdge(int u, int v, bool w) {
		nodes[u].emplace_back(u, v, w);
	}

	void bfs01(int src, vector<int> &parent) {
		deque<pair<int, int>> L; L.push_back({ src, src });
		
		parent.resize(n, -1); while (!L.empty()) {
			if (parent[L.front().first] != -1) { L.pop_front(); continue; }
			int cur = L.front().first; parent[cur] = L.front().second; L.pop_front();

			for (Edge& e : nodes[cur]) if (parent[e.v] == -1) {
				e.w ? L.push_back({ e.v, cur }) : L.push_front({ e.v, cur });
			}
		}
	}
};

int di[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dj[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int n, m; vector<string> S; vector<int> vis;

bool check(int i, int j, int k) {
	if (i + di[k] < 0 || i + di[k] > n - 1) return false;
	if (j + dj[k] < 0 || j + dj[k] > m - 1) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> m; Graph G(n * m + 2);
		S.resize(n); vis.clear(); vis.resize(n * m);
		for (auto& x : S) cin >> x;

		for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)
			if (S[i][j] == '#')	for (int k = 0; k < 4; k++)
				if (check(i, j, k)) vis[(i + di[k]) * m + j + dj[k]] = 1;

		for (int i = 0; i < n; i++) {
			if (!vis[i * m]) G.addEdge(n * m, i * m, S[i][0] == '.');
			if (!vis[i * m + m - 1]) G.addEdge(i * m + m - 1, n * m + 1, 0);
		}

		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (!vis[i * m + j]) for (int k = 4; k < 8; k++)
				if (check(i, j, k) && !vis[(i + di[k]) * m + j + dj[k]])
					G.addEdge(i * m + j, (i + di[k]) * m + j + dj[k], S[i + di[k]][j + dj[k]] == '.');

		vector<int> par; G.bfs01(n * m, par);
		if (par[n * m + 1] == -1) { cout << "NO\n"; continue; }

		cout << "YES\n";
		for (int cur = par[n * m + 1]; cur != n * m; cur = par[cur]) {
			S[cur / m][cur % m] = '#';
		}
		for (auto& x : S) cout << x << '\n';
	}
}