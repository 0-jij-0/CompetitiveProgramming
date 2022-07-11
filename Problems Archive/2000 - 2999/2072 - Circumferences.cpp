#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;

struct Circle {
	ll x = 0, y = 0, r = 1; Circle() {}
	Circle(ll _x, ll _y, ll _r) : x(_x), y(_y), r(_r) {}

	bool count(ll _x, ll _y) {
		ll dx = x - _x, dy = y - _y;
		ll d = dx * dx + dy * dy;
		return d == r * r;
	}
};

bool intersect(Circle A, Circle B) {
	if (A.r < B.r) { swap(A, B); }
	ll dx = A.x - B.x, dy = A.y - B.y;
	ll d = dx * dx + dy * dy;
	if (d < A.r) { return d >= (A.r - B.r) * (A.r - B.r); }
	return d <= (A.r + B.r) * (A.r + B.r);
}

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

vector<Circle> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, sx, sy, tx, ty; cin >> n >> sx >> sy >> tx >> ty;
	int s = 0, t = 0;
	for (int i = 0; i < n; i++) {
		int x, y, r; cin >> x >> y >> r;
		v.emplace_back(x, y, r);
		if (v.back().count(sx, sy)) { s = i; }
		if (v.back().count(tx, ty)) { t = i; }
	}

	DSU dsu(n);
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (intersect(v[i], v[j]))
				dsu.merge(i, j);

	cout << (dsu.find(s) == dsu.find(t) ? "Yes" : "No") << '\n';
}