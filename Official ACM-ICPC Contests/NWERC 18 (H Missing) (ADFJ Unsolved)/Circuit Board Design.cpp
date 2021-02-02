#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double ld;
const ld pi = 3.14159265359;

vector<pair<ld, ld>> res;

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	vector<int> subSize;
	graph(int _n) : n(_n), nodes(_n), subSize(_n, 0) { res.resize(_n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}

	int subSizeDFS(int cur, int p = -1) {
		int res = 1; for (auto &e : nodes[cur].edges)
			if (e != p) res += subSizeDFS(e, cur);
		return subSize[cur] = res;
	}
	
	void dfs(int cur, ld x, ld y, int l, int p = -1) {
		res[cur] = { x, y }; int cL = l;
		for (auto &e : nodes[cur].edges) {
			if (e == p) { continue; }
			ld dx = cos(cL * pi / 1000.0);
			ld dy = sin(cL * pi / 1000.0);
			dfs(e, x + dx, y + dy, cL, cur); 
			cL += subSize[e];
		}
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		u--; v--; g.add_edge(u, v);
	}
	g.subSizeDFS(0); g.dfs(0, 0.0, 0.0, 0);
	cout << fixed << setprecision(15); 
	/*ld ma = 10000.0; for(int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			ld dx = res[i].first - res[j].first;
			ld dy = res[i].second - res[j].second;
			ma = min(ma, sqrt(dx * dx + dy * dy));
		} cout << ma << '\n'; */
	for (auto &x : res) cout << x.first << ' ' << x.second << '\n';
	cin.ignore(2); return 0;
}