#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node { vector<int> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(v);
		nodes[v].edges.emplace_back(u);
	}

	int bfs(int u, vector<int> &d) {
		queue<pair<int, int>> q; q.push({ u, -1 });
		vector<bool> vis(n, 0); vector<int> par(n, -1);
		
		vis[u] = true; while (!q.empty()) {
			int cur = q.front().first;
			int p = q.front().second;
			q.pop(); par[cur] = p; 
			
			for (auto& e : nodes[cur].edges) {
				if (vis[e]) { continue; }
				int nextP = (p == -1 ? e : p);
				d[e] += d[cur]; vis[e] = true;
				q.push({ e, nextP }); 
			}
		}

		int idx = max_element(d.begin(), d.end()) - d.begin();
		int res = d[u]; for (int i = 0; i < n; i++) if (i != u) {
			if (par[i] != par[idx]) res = max(res, d[i]);
		}
		return d[idx] + res - d[u];
	}
};

vector<int> C;

int main() {
	ifstream cin("C1.in.txt");
	ofstream cout("C1.out.txt");

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; graph g(n); C.resize(n);
		for (auto& x : C) { cin >> x; }

		for (int i = 1; i < n; i++) {
			int u, v; cin >> u >> v;
			g.add_edge(--u, --v);
		}

		cout << "Case #" << t << ": " << g.bfs(0, C) << '\n';
	}

	return 0;
}