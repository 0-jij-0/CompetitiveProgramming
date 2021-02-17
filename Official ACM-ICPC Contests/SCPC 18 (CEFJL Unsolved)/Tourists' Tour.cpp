#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <cassert>
#include <climits>
using namespace std;

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

struct graph {
	vector<node> nodes;
	vector<int> color;
	int n;

	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		edge e1(u, v); nodes[u].edges.push_back(e1);
		edge e2(v, u); nodes[v].edges.push_back(e2);
	}

	bool twoColorDfs(int u) {
		stack<int> S; S.push(u); color[u] = 0;
		while (!S.empty()) {
			int cur = S.top(); S.pop();
			for (auto& e : nodes[cur].edges) {
				if (color[e.v] == -1) { color[e.v] = color[e.u] ^ 1; S.push(e.v); }
				else if (color[e.v] == color[e.u]) { return false; }
			}
		}
		return true;
	}

	bool twoColor() {
		color.clear(); color.resize(n, -1);
		for (int i = 0; i < n; i++) {
			if (color[i] != -1) { continue; }
			if (!twoColorDfs(i)) { return false; }
		}
		return true;
	}

	void moreColor(vector<pair<int, int>>& order) {
		color.clear(); color.resize(n, -1);
		for (int ii = 0; ii < n; ii++) {
			int i = order[ii].second;
			bool used[4]; used[0] = used[1] = used[2] = used[3] = 0;
			for (auto& e : nodes[i].edges) {
				if (color[e.v] != -1) { used[color[e.v]] = 1; }
			}
			for (int j = 0; j < 4; j++) {
				if (!used[j]) { color[i] = j; break; }
			}
		}
	}
};

void findEdges(graph& g, vector<int>& h) {
	stack<pair<int, int>> S; S.push({ h[0], 0 });
	for (int i = 1; i < g.n; i++) {
		while (!S.empty() && S.top().first < h[i]) { g.add_edge(S.top().second, i); S.pop(); }
		if (!S.empty()) { g.add_edge(i, S.top().second); }
		S.push({ h[i], i });
	}
}

int main() {
	freopen("tour.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; graph g(n);
		vector<int> h(n); for (auto& x : h) { cin >> x; }
		if (n == 1) { cout << 1 << '\n' << 1 << '\n'; continue; }
		findEdges(g, h); vector<pair<int, int>> order(n);
		for (int i = 0; i < n; i++) { order[i] = { h[i], i }; }
		sort(order.rbegin(), order.rend());

		if (!g.twoColor()) { g.moreColor(order); }
		cout << *max_element(g.color.begin(), g.color.end()) + 1 << '\n';
		for (auto& x : g.color) cout << x + 1 << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}