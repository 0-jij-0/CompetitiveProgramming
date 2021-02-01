#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;	int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	int dfs(int u, vector<bool> &visited) {
		stack<int> s; s.push(u); int res = 0;
		visited[u] = true;
		while (!s.empty()) {
			int f = s.top(); s.pop(); res++;
			node& n = nodes[f];
			for (auto &x: n.edges) {
				int dest = x.v;
				if (visited[dest] == false)	{
					s.push(dest); visited[dest] = true;
				}
			}
		}
		return res;
	}
};

int main() {
	int n, k; cin >> n >> k; graph g(n);
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		a--; b--; g.add_edge(a, b);
	}
	vector<bool> visited(n, false);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) { continue; }
		res += g.dfs(i, visited) - 1;
	}
	cout << k - res << endl;
	cin.ignore(2); return 0;
}