#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, w, id; edge() {}
	edge(int _u, int _v, int _w = 0, int _id = 0) :
		u(_u), v(_v), w(_w), id(_id) {}
	bool operator < (const edge& rhs) const { return w < rhs.w; }
};

struct node { int id; vector<edge> edges; };

struct graph {
	vector<edge> edges;
	vector<node> nodes;
	int n, m;

	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v, int w = 0) {
		edge e1(u, v, w, m), e2(v, u, w, m);
		nodes[u].edges.push_back(e1);
		nodes[v].edges.push_back(e2);
		edges.push_back(e1); m++;
	}

	vector<int> euler_undirected(int n) {
		int start = -1, odddeg = 0;
		for (int i = 0; i < n; ++i) {
			if ((int)nodes[i].edges.size() & 1) { odddeg++, start = i; }
			else if (!nodes[i].edges.empty() && start == -1) { start = i; }
		}
		if (odddeg > 2) { return vector<int>(); }
		vector<bool> used(m, 0);
		vector<int> stack, res, which(n + 1, 0);
		stack.push_back(start);
		while (!stack.empty()) {
			int v = stack.back();
			while (which[v] < (int)nodes[v].edges.size() && used[nodes[v].edges[which[v]].id]) { which[v]++; }
			if (which[v] == (int)nodes[v].edges.size()) {
				stack.pop_back(); res.push_back(v);
			}
			else {
				int ed = nodes[v].edges[which[v]].id;
				int w = (edges[ed].u) == v ? edges[ed].v : edges[ed].u;
				used[ed] = 1; stack.push_back(w);
			}
		}
		if (count(used.begin(), used.end(), false)) { return vector<int>(); }
		return move(res);
	}
};

vector<int> b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n; cin >> n;
	b.resize(n - 1); c.resize(n - 1);
	for (auto &x : b) { cin >> x; }
	for (auto &x : c) { cin >> x; }

	vector<int> v(b.begin(), b.end());
	v.insert(v.end(), c.begin(), c.end());
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto &x : b) { x = lower_bound(v.begin(), v.end(), x) - v.begin(); }
	for (auto &x : c) { x = lower_bound(v.begin(), v.end(), x) - v.begin(); }

	graph g((int)v.size());
	for (int i = 0; i < n - 1; i++) {
		if (b[i] <= c[i]) { g.add_edge(b[i], c[i]); }
		else { cout << -1 << endl; cin.ignore(2); return 0; }
	}

	vector<int> res = g.euler_undirected((int)v.size());
	if (res.empty()) { cout << -1 << endl; cin.ignore(2); return 0; }
	for (int i = 0; i < n; i++) {
		cout << v[res[i]];
		if (i + 1 != n) { cout << ' '; }
		else { cout << endl; }
	}
	cin.ignore(2); return 0;
}