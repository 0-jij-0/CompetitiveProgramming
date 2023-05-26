#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<set<int>> nodes; int N;
	Graph(int _n) : N(_n), nodes(_n) {}

	void addEdge(int u, int v) {
		nodes[u].insert(v);
		nodes[v].insert(u);
	}

	bool bfs(int u, vector<bool>& vis) {
		queue<int> q; q.push(u); 
		bool cycle = true; vis[u] = true;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			cycle &= nodes[cur].size() != 1;
			for (auto& e : nodes[cur]) {
				if (vis[e]) { continue; }
				q.push(e); vis[e] = true;
			}
		}
		return cycle;
	}
};

vector<int> A;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t; while(t--) {
		int n; cin >> n; Graph G(n);
		for (int i = 0; i < n; ++i) {
			int a; cin >> a; G.addEdge(i, --a);
		}

        int other = 0, cycle = 0;
        vector<bool> vis(n, 0);
		for (int i = 0; i < n; ++i) if (!vis[i])
			(G.bfs(i, vis) ? cycle : other)++;
       
        cout << cycle + (other != 0) << ' ' << cycle + other << '\n';
    }
}