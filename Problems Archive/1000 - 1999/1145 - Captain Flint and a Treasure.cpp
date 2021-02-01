#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

vector<ll> a; vector<int> b, in;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v);
	}

	void bfs(vector<int> &U) {
		vector<int> vis(n, 0), par(n, -1); queue<int> q; 
		for (auto &u : U) { q.push(u); vis[u] = true; }
		vector<int> order;
		while (!q.empty()) {
			int cur = q.front(); q.pop(); 
			order.push_back(cur);
			for (edge &e : nodes[cur].edges) {
				if (vis[e.v]) { continue; }
				q.push(e.v); vis[e.v] = 1; par[e.v] = cur;
			}
		}
		ll res = 0; vector<int> ans;
		for (int i = n - 1; i >= 0; i--) {
			int &cur = order[i]; if (a[cur] < 0) { continue; }
			res += a[cur]; ans.push_back(cur);
			if(par[cur] != -1) a[par[cur]] += a[cur];
		}
		for(int i = 0; i < n; i++) if (a[order[i]] < 0) { 
			res += a[order[i]]; ans.push_back(order[i]); 
		}
		cout << res << '\n';
		for (auto &x : ans) cout << x + 1 << ' ';
		cout << '\n';
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; graph g(n);
	in.clear(); a.resize(n); b.resize(n);
	for (auto &x : a) { cin >> x; }
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x == -1) { in.push_back(i); continue; }
		x--; g.add_edge(x, i);
	}
	
	g.bfs(in); cin.ignore(2); return 0;
}