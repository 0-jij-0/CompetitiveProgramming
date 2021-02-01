#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<int, int>> s, t;

struct edge {
	int u, v; bool matched = 0; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { bool matched = 0; vector<edge> edges; };

struct bipartiteGraph {
	vector<node> nodes; int n, m;
	vector<int> match;
	vector<bool> vis;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m);
		match.resize(n + m, -1); vis.resize(n + m, 0);
	}
	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
	}

	bool augment(int v) {
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges) {
			if (match[e.v] == -1 || augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		}
		return 0;
	}

	int matching() {
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges) {
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++;  break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (match[i] != -1) { continue; }
			for (int j = 0; j < n; j++) { vis[j] = 0; }
			w += augment(i);
		}
		return w;
	}
};

int distance(const pair<int, int> &p1, const pair<int, int> &p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool check(const int &n, const int &k) {
	bipartiteGraph g(n, n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (distance(s[i], t[j]) <= k)
				g.add_edge(i, j + n);

	return g.matching() == n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; s.resize(n); t.resize(n);
	for (auto &x : s) { cin >> x.first >> x.second; }
	for (auto &x : t) { cin >> x.first >> x.second; }

	int l = 0, r = 1 << 30;
	while (l < r) {
		int mid = (l + r) / 2;
		bool b = check(n, mid);
		if (b) { r = mid; }
		else { l = mid + 1; }
	}
	cout << l << '\n'; cin.ignore(2); return 0;
}