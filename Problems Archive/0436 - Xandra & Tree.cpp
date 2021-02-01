#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	ll size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v; ll w; edge() {}
	edge(int _u, int _v, ll _w) :
		u(_u), v(_v), w(_w) {}
	bool operator < (const edge &rhs)const { return w < rhs.w; }
};

vector<edge> edges;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n; edges.resize(n - 1);
	for (auto &x : edges) {
		int a, b; ll w; cin >> a >> b >> w;
		edge e(a, b, w); x = e;
	}
	sort(edges.begin(), edges.end());
	ll res = 0; DSU dsu(n + 1);
	for (auto &x : edges) {
		ll add = (dsu.size(x.u)*dsu.size(x.v)) % mod;
		res += (add * x.w) % mod; res %= mod; 
		dsu.merge(x.u, x.v);
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}