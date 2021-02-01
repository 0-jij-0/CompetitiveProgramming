#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> depth, parent; int n;

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
		edge e1(u, v), e2(v, u);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
	}

	void dfs(const int &cur, int p) {
		for (edge &e : nodes[cur].edges) {
			if (e.v == p) { continue; }
			depth[e.v] = 1 + depth[cur];
			parent[e.v] = cur; dfs(e.v, cur);
		}
	}
};

bool query(const int &l, const int &r, int x = -1) {
	int b = 0; string q = "";
	for (int i = 0; i < n; i++)
		if (i != x && depth[i] <= r && depth[i] >= l) {
			b++; q += " " + to_string(i + 1);
		}
	if (!b) { return false; }
	cout << "? " << b << q << endl; return true;
}

int firstRes(const int &d) {
	int l = 0, r = d / 2, cur = -1, len;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		if (!query(mid, r)) { r = mid - 1; continue; }
		cin >> cur >> len;
		len != d ? r = mid - 1 : l = depth[cur - 1];
	}
	if (cur == -1) { query(l, l); cin >> cur >> len; return cur; }
	return len == d ? cur : parent[cur];
}

int secondRes(const int &d, int first) {
	int except = -1;
	if (d && depth[first] >= d) {
		while (depth[first] != d) { first = parent[first]; }
		except = first;
	}

	int b = 0; string q = "";
	for (int i = 0; i < n; i++)
		if (i != except && depth[i] == d) {
			b++; q += " " + to_string(i + 1);
		}
	if (b == 1) { return stoi(q); }
	cout << "? " << b << q << endl;
	int res, len; cin >> res >> len; return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n; depth.clear(); depth.resize(n, 0);
		parent.clear(); parent.resize(n, -1); graph g(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; cin >> u >> v;
			g.add_edge(u - 1, v - 1);
		}

		query(0, 0); int root, d;
		cin >> root >> d; g.dfs(root - 1, -1);

		int res1 = firstRes(d), len = d - depth[res1 - 1];
		int res2 = len ? secondRes(len, res1 - 1) : root;
		cout << "! " << res1 << ' ' << res2 << endl;
		string res; cin >> res; if (res != "Correct") { exit(0); }
	}
	cin.ignore(2); return 0;
}