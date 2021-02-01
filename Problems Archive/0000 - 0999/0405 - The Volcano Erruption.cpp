#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef long long ll;

struct circle {
	ll x, y, r; circle() {}
	circle(ll _x, ll _y, ll _r) :
		x(_x), y(_y), r(_r) {}
	bool inter(circle &rhs) {
		ll dx = x - rhs.x, dy = y - rhs.y;
		return (r + rhs.r)*(r + rhs.r) >= (dx*dx + dy*dy);
	}
};

vector<circle> c;

struct DSU {
	vector<int> rank, parent;
	vector<ll> minx, maxx;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		minx.resize(n); maxx.resize(n);
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) {
			minx[i] = c[i].x - c[i].r;
			maxx[i] = c[i].x + c[i].r;
		}
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		minx[u] = min(minx[u], minx[v]);
		maxx[u] = max(maxx[u], maxx[v]);
		minx[v] = maxx[v] = 0;
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, w, l; cin >> n >> w >> l;
		c.clear(); c.resize(n);
		for (int i = 0; i < n; i++) {
			ll x, y, r; cin >> x >> y >> r;
			circle ci(x, y, r); c[i] = ci;
		}
		DSU dsu(n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (c[i].inter(c[j]))
					dsu.merge(i, j);

		int res = 0;
		for (int i = 0; i < n; i++)
			if (dsu.minx[i] <= 0 && dsu.maxx[i] >= w) { res++; }
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}