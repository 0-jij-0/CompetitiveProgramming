#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <iomanip>
using namespace std;
typedef double ld;

vector<pair<int, int>> v; int n;

struct DSU {
	vector<int> rank, parent;

	DSU(int _n) : rank(_n, 1), parent(_n) {
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

bool intersect(int x1, int y1, int x2, int y2, ld r) {
	int dx = x1 - x2; dx *= dx;
	int dy = y1 - y2; dy *= dy;
	return dx + dy < 4 * r * r;
}

bool check(ld r) {
	DSU dsu(n + 2);
	for (int i = 0; i < n; i++) {
		int& xi = v[i].first, & yi = v[i].second;
		if (yi + r > 100 - r) { dsu.merge(i, n); }
		if (yi - r < -100 + r) { dsu.merge(i, n + 1); }
		for (int j = i + 1; j < n; j++) {
			int& xj = v[j].first, & yj = v[j].second;
			if (intersect(xi, yi, xj, yj, r)) dsu.merge(i, j);
		}
	}
	return dsu.find(n) != dsu.find(n + 1);
}

ld findMaxRadius() {
	ld l = 0.0, r = 100.0;
	while (r - l > 1e-6) {
		ld mid = (r + l) / 2;
		check(mid) ? l = mid : r = mid;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n; v.resize(n);
	for (auto& x : v) cin >> x.first >> x.second;
	cout << fixed << setprecision(10) << findMaxRadius() << '\n';

	cin.ignore(2); return 0;
}