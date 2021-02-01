#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

map<string, int> idx;

struct recepe {
	string rec, bas, add;
	int price, prest; recepe() {}
};

vector<recepe> v;
vector<pair<int, int>> CP;

struct node { vector<vector<int>> edges; vector<pair<int, int>> val; };

struct graph {
	vector<node> nodes; int n;
	graph(int _n) : n(_n) { nodes.resize(n); }

	void add_edge(int u, int v) {
		nodes[u].edges.back().push_back(v);
	}

	pair<int, int> dfs(int cur) {
		if (nodes[cur].edges.empty()) { return CP[cur] = { 0, 0 }; }
		if (CP[cur].first != -1) { return CP[cur]; }
		int price = 1 << 20, prest = 0, n = (int)nodes[cur].edges.size();
		for (int i = 0; i < n; i++) {
			int c = nodes[cur].val[i].first, p = nodes[cur].val[i].second;
			for (int &e : nodes[cur].edges[i]) {
				pair<int, int> P = dfs(e);
				c += P.first; p += P.second;
			}
			if (c > price) { continue; }
			if (c < price) { price = c; prest = p; continue; }
			if (p > prest) { prest = p; }
		}
		return CP[cur] = { price, prest };
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int b, n; cin >> b >> n; v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].rec >> v[i].bas >> v[i].add
			>> v[i].price >> v[i].prest;
		idx[v[i].rec]++; idx[v[i].bas]++; idx[v[i].add]++;
	}
	int id = 0; for (auto &x : idx) { x.second = id++; }
	graph g(id); CP.resize(id, { -1, -1 });

	for (auto &x : v) {
		int i = idx[x.rec]; g.nodes[i].edges.push_back({});
		g.nodes[i].val.push_back({ x.price, x.prest });
		g.add_edge(i, idx[x.bas]); g.add_edge(i, idx[x.add]);
	}
	for (int i = 0; i < id; i++) { g.dfs(i); }

	vector<int> dp(b + 1, -(1 << 30)); dp[0] = 0;
	for (int i = 0; i < CP.size(); i++) {
		if (CP[i].first == 0 && CP[i].second == 0) { continue; }
		for (int j = b; j >= 0; j--) {
			int newCost = j + CP[i].first;
			if (newCost > b) { continue; }
			dp[newCost] = max(dp[newCost], dp[j] + CP[i].second);
		}
	}

	int maxPrest = 0, maxCost = 0;
	for (int i = 0; i < b + 1; i++)
		if (dp[i] > maxPrest) { maxPrest = dp[i]; maxCost = i; }
	cout << maxPrest << '\n' << maxCost << '\n';
	cin.ignore(2); return 0;
}