#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;

struct edge {
	int u, v; bool match = 0; edge() {}
	edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node { vector<edge> edges; node() {} };

//Classic Problems:
//Maximum Matching - Minimum Vertex Cover
//Minimum Path Cover - Maximum Bipartite Clique
struct bipartiteGraph {
	//Matching: Set of edges that do not share a node
	//Vertex Cover: Set of nodes that cover all edges
	//Cut Capacity: Set of edges that disconnect source(L) from sink(R) upon removal
	//Independent Set: Set of nodes not connected by edges

	//Complement of vertex cover = independent Set
	//Clique in graph = Independent Set in inverse Graph
	vector<node> nodes; int n, m;
	vector<bool> Z, vis;
	vector<int> unMatched, match;

	bipartiteGraph(int _n, int _m) : n(_n), m(_m) {
		nodes.resize(n + m); Z.resize(n + m, 0);
		match.resize(n + m, -1); vis.resize(n + m, 0);
	}

	void add_edge(int u, int v) {
		nodes[u].edges.push_back(edge(u, v));
		nodes[v].edges.push_back(edge(v, u));
	}

	bool augment(int v) {
		if (v == -1) { return 1; }
		if (vis[v]) { return 0; }
		vis[v] = 1;
		for (auto &e : nodes[v].edges)
			if (augment(match[e.v])) {
				match[e.v] = v; match[v] = e.v;
				return 1;
			}
		return 0;
	}

	//In Bipartite Graphs (Konig's Theorem)
	//Max Matching = Min Vertex Cover = Max Flow = Min Cut
	int maxMatching() { //With Greedy initialization
		int w = 0;
		for (int x = 0; x < n; x++) {
			if (match[x] != -1) { continue; }
			for (auto &e : nodes[x].edges)
				if (match[e.v] == -1) {
					match[e.v] = x; match[x] = e.v;
					w++; break;
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

vector<pair<int, int>> B, R;

ll dist(pair<int, int> &p1, pair<int, int> &p2) {
	ll dx = p1.first - p2.first;
	ll dy = p1.second - p2.second;
	return dx * dx + dy * dy;
}

bool check(ll k, const int &b, const int &r, const int &n) {
	bipartiteGraph g(b, r);
	for (int i = 0; i < b; i++)
		for (int j = 0; j < r; j++)
			if (dist(B[i], R[j]) < k)
				g.add_edge(i, b + j);
	return (b + r) - g.maxMatching() >= n;
}

ll findMax(const int &b, const int &r, const int &n) {
	ll L = 0, R = 1ll << 40;
	while (L != R) {
		ll mid = (L + R + 1) >> 1;
		bool ok = check(mid, b, r, n);
		ok ? L = mid : R = mid - 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, b, r; cin >> n >> b >> r;
	B.resize(b); R.resize(r); 
	for (auto &x : B) { cin >> x.first >> x.second; }
	for (auto &x : R) { cin >> x.first >> x.second; }
	cout << fixed << setprecision(6) << sqrt(findMax(b, r, n)) << endl;

	cin.ignore(2); return 0;
}