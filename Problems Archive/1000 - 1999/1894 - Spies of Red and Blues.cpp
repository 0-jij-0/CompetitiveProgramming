#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int NR, NB;

struct graph {
	vector<int> nodes;
	vector<int> dist, type; int n;
	graph(int _n) : n(_n), dist(_n), type(_n), nodes(_n) {}

	pair<int, int> dfs(int cur, vector<int>& col) {
		if (col[cur] == 2) { return { dist[cur], type[cur] }; }
		if (cur == 0) { col[cur] = 2; return { dist[cur] = 0, type[cur] = 0 }; }
		if (cur == NR) { col[cur] = 2; return { dist[cur] = 0, type[cur] = 1 }; }
		col[cur] = 1; int e = nodes[cur]; 
		if (col[e] == 1) { col[cur] = 2; return { dist[cur] = -(1 << 30), type[cur] = -1 }; }
		auto res = dfs(e, col); col[cur] = 2; return { dist[cur] = res.first + 1, type[cur] = res.second };
	}

	string query(int u, int v) {
		if (dist[u] > dist[v]) { swap(u, v); }
		if (dist[v] < 0) { return "NONE"; }
		if (dist[u] < 0) { return (type[v] ? "BLUE " : "RED ") + to_string(dist[v]); }
		if (type[u] == type[v]) { return (type[u] ? "BLUE " : "RED ") + to_string(dist[u]); }
		if (dist[u] == dist[v]) { return "TIE " + to_string(dist[u]); }
		return (type[u] ? "BLUE " : "RED ") + to_string(dist[u]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int E; cin >> NR >> NB >> E; graph g(NR + NB);
		for (int i = 1; i < NR; i++) {
			char c; int x; cin >> c >> x;
			g.nodes[i] = --x;
		}

		for (int i = 1; i < NB; i++) {
			char c; int x; cin >> c >> x;
			g.nodes[i + NR] = --x + NR;
		}

		vector<int> col(NR + NB, 0);
		for (int i = 0; i < NR + NB; i++)
			if (!col[i]) g.dfs(i, col);

		while (E--) {
			char q, X, Y; int x, y;
			cin >> q >> X >> x >> Y >> y;
			x += (X == 'B') * NR;
			y += (Y == 'B') * NR;
			if (q == 'w') cout << g.query(--x, --y) << '\n';
			else {
				g.nodes[--x] = --y;
				col = vector<int>(NR + NB, 0);
				for (int i = 0; i < NR + NB; i++)
					if (!col[i]) g.dfs(i, col);
			}
		}
	}

	cin.ignore(2); return 0;
}