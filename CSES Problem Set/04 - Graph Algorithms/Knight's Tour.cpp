#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> res(64, 0);

struct edge {
	int u, v; edge() {}
	edge(int _u, int _v) :
		u(_u), v(_v) {}
};

struct node { vector<edge> edges; };

int dx[4] = { 1, -1, 2, -2 };
int dy[4] = { 2, 2, 1, 1 };

struct graph {
	vector<node> nodes;
	vector<int> out; int n;
	graph(bool b) : n(64), nodes(64), out(64) { 
		for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++)
			for (int k = 0; k < 4; k++)	if (check(i, j, k))
				add_edge(i * 8 + j, (i + dy[k]) * 8 + j + dx[k]);
	}

	bool check(int i, int j, int k) {
		if (i + dy[k] < 0 || i + dy[k] > 7) { return false; }
		if (j + dx[k] < 0 || j + dx[k] > 7) { return false; }
		return true;
	}

	void add_edge(int u, int v) {
		nodes[u].edges.emplace_back(u, v); out[u]++;
		nodes[v].edges.emplace_back(v, u); out[v]++;
	}

	bool dfs(int cur, int t) {
		if (res[cur]) { return t == 65; }
		res[cur] = t; int next = nodes[cur].edges.front().v;
		for (auto& e : nodes[cur].edges) --out[e.v];

		auto comp = [&](const edge& e1, const edge& e2) {
			if ((res[e1.v] != 0) ^ (res[e2.v] != 0)) { return res[e2.v] != 0; }
			return out[e1.v] < out[e2.v];
		}; sort(nodes[cur].edges.begin(), nodes[cur].edges.end(), comp);

		for (auto& e : nodes[cur].edges) if (dfs(e.v, t + 1)) return true;
		for (auto& e : nodes[cur].edges) ++out[e.v];
		res[cur] = 0; return false;
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int x, y; cin >> x >> y; x--; y--;
	graph g(true); g.dfs(y * 8 + x, 1);

	for (int i = 0; i < 64; i++)
		cout << res[i] << " \n"[i % 8 == 7];

	cin.ignore(2); return 0;
}