#include <bits/stdc++.h>
using namespace std;

struct Graph {
	vector<vector<int>> nodes; int n;
	vector<int> inDegree;
	Graph(int _n) : n(_n), nodes(_n), inDegree(_n) {}

	void addEdge(int u, int v) {
		inDegree[v]++;
		nodes[u].emplace_back(v);
	}

	void bfs(vector<set<int>> &res) {
		vector<int> cur; 
		for (int i = 0; i < n; i++)
			if (!inDegree[i]) cur.push_back(i);

		for (int i = 0; i < n; i++) res[i].insert(i); 
		
		int last = (int)cur.size();
		while (!cur.empty()) {
			vector<int> nxt;
			for (auto& x : cur) {
				for (auto& e : nodes[x]) {
					if (!(--inDegree[e])) nxt.push_back(e);
					for (auto& y : res[x]) res[e].insert(y);
				}
			}
			cur = move(nxt);
		}
	}
};

vector<string> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); Graph G(n);
		for (auto& x : v) cin >> x;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (v[i][j] == '1')	G.addEdge(i, j);
		
		vector<set<int>> res(n); G.bfs(res);
		for (auto& x : res) {
			cout << x.size() << ' '; for (auto& y : x) 
				cout << y + 1 << ' '; cout << '\n';
		}
	}
}