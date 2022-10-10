#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; char c = '0'; edge() {}
	edge(int _u, int _v, char _c) :
		u(_u), v(_v), c(_c) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, char c) {
		nodes[u].edges.emplace_back(u, v, c);
	}

	void bfs(int s, int d) {
		vector<edge> parent(n); vector<bool> vis(n, false);
		queue<int> q; q.push(s); vis[s] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				q.push(e.v); vis[e.v] = true;
				parent[e.v] = e;
			}
		}
		if (parent[d].c == '0') { cout << "NO\n"; return; }
		cout << "YES\n"; string res = "";
		while (d != s) { res.push_back(parent[d].c); d = parent[d].u; }
		reverse(res.begin(), res.end()); cout << res.size() << '\n' << res << '\n';
	}
};

vector<string> v; int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char ch[4] = { 'U', 'D', 'L', 'R' };

void connect(graph &g, int i, int j, int u, int v, char c) {
	if (u < 0 || u > n - 1) { return; }
	if (v < 0 || v > m - 1) { return; }
	g.add_edge(i * m + j, u * m + v, c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }
	int s = 0, e = 0; graph g(n * m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '#') { continue; }
			if (v[i][j] == 'A') { s = i * m + j; }
			if (v[i][j] == 'B') { e = i * m + j; }
			for (int k = 0; k < 4; k++) 
				connect(g, i, j, i + dx[k], j + dy[k], ch[k]);
		}
	g.bfs(s, e);
}