#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v; char c; edge() {}
	edge(int _u, int _v, char _c) :
		u(_u), v(_v), c(_c) {}
};

struct node { int x = 0; vector<edge> edges; };

vector<string> v; int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char d[4] = { 'U', 'D', 'L', 'R' };

void bfs() {
	vector<int> visited(n * m, false);
	vector<edge> parent(n * m);
	queue<pair<int, int>> q;
	int source = 0, dest = -1;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '#') { visited[i * m + j] = true; continue; }
			if (v[i][j] == 'A') { source = i * m + j; continue; }
			if (v[i][j] == 'M') { q.push({ i * m + j , 0 }); visited[i *m + j] = true; continue; }
		}
	q.push({ source, 1 }); visited[source] = true;
	while (!q.empty()) {
		int cur = q.front().first, b = q.front().second; q.pop();
		int x = cur / m, y = cur % m;
		if (b && (x == 0 || x == n - 1 || y == 0 || y == m - 1)) { dest = cur; break; }
		for (int i = 0; i < 4; i++) {
			if (x + dx[i] < 0 || x + dx[i] > n - 1) { continue; }
			if (y + dy[i] < 0 || y + dy[i] > m - 1) { continue; }
			int v = (x + dx[i]) * m + y + dy[i]; if (visited[v]) { continue; }
			parent[v] = edge(cur, v, d[i]); q.push({ v, b }); visited[v] = true;
		}
	}
	if (dest == -1) { cout << "NO\n"; return; }
	cout << "YES\n"; string res = "";
	while (dest != source) { res.push_back(parent[dest].c); dest = parent[dest].u; }
	reverse(res.begin(), res.end()); cout << res.size() << '\n' << res << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m; v.resize(n);
	for (auto &x : v) { cin >> x; }

	bfs();
}