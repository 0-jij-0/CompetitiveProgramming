#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

struct node { long long f, x, y; };
vector<node> nodes;
vector<vector<long double>> g;
vector<vector<long double>> D;
vector<vector<int>> helper;
const long double maxi = INT_MAX + 0.0;

long double dist(const node &a, const node &b) {
	return (long double) sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

void add_edge(int u, int v, int t) {
	long double w = 0;
	if (t == 0) {
		long double a = abs(nodes[u].f - nodes[v].f) * 5.0;
		long double b = dist(nodes[u], nodes[v]);
		w = (long double)sqrt(a*a + b*b);
		g[u][v] = g[v][u] = w;
	}
	else if (t == 1) {
		g[u][v] = g[v][u] = 1.0 + dist(nodes[u], nodes[v]);
	}
	else {
		g[u][v] = 1.0;
		long double a = abs(nodes[u].f - nodes[v].f) * 5.0;
		long double b = dist(nodes[u], nodes[v]);
		w = (long double)sqrt(a*a + b * b); g[v][u] = 3.0 * w;
	}
}

void allPairsShortestPath() {
	int n = nodes.size();
	D.resize(n); helper.resize(n);
	for (int i = 0; i < n; i++) { D[i].resize(n); helper[i].resize(n, -1); }

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			D[i][j] = g[i][j];

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					helper[i][j] = k;
				}
}

void get_path(int i, int j) {
	if (helper[i][j] == -1) { cout << i << ' '; }
	else { 
		get_path(i, helper[i][j]);
		get_path(helper[i][j], j);
	}
}


int main() {
	int n, m; cin >> n >> m; g.resize(n); nodes.resize(n);
	for (int i = 0; i < n; i++) { g[i].resize(n, maxi); }
	for (auto &x : nodes) { cin >> x.f >> x.x >> x.y; }
	for (int i = 0; i < m; i++) {
		int u, v; string s; cin >> u >> v >> s;
		if (s == "lift") { add_edge(u, v, 1); }
		else if (s == "escalator") { add_edge(u, v, 2); }
		else { add_edge(u, v, 0); }
	}
	for (int i = 0; i < n; i++) { g[i][i] = 0.0; }
	allPairsShortestPath();
	
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v;
		get_path(u, v);
		cout << v << endl;
	}

	cin.ignore(2); return 0;
}