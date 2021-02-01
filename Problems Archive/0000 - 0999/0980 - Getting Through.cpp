#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double ld;

struct circle { int x, y, r; circle() {} };
vector<circle> C;

struct DSU {
	vector<int> rank, parent;
	vector<ld> minX, maxX;

	DSU(int n, ld R) : minX(n), maxX(n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) {  
			minX[i] = C[i].x - C[i].r - R;
			maxX[i] = C[i].x + C[i].r + R;
		}
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) { return false; }
		if (rank[a] < rank[b]) { swap(a, b); }
		rank[a] += rank[b];	parent[b] = a;
		minX[a] = min(minX[a], minX[b]);
		maxX[a] = max(maxX[a], maxX[b]);
		return true;
	}
};

ll dist2(int x1, int y1, int x2, int y2) {
	ll dx = x1 - x2, dy = y1 - y2;
	return dx * dx + dy * dy;
}

bool inter(const circle  &c1, const circle &c2, ld R) {
	ld d = dist2(c1.x, c1.y, c2.x, c2.y);
	ld D = c1.r + c2.r + R + R; D *= D;
	return d < D;
}

bool check(ld R, int n, int w) {
	DSU dsu(n, R);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (inter(C[i], C[j], R)) { dsu.merge(i, j); }

	for (int i = 0; i < n; i++)
		if (dsu.minX[i] < R && dsu.maxX[i] > w - R)
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int w, n; cin >> w >> n; C.resize(n);
		for (auto &x : C) { cin >> x.x >> x.y >> x.r; }
		ld l = 0.0, r = w + 1.0;
		while (r - l > 1e-7) {
			ld mid = (l + r) / 2.0;
			bool b = check(mid, n, w);
			b ? l = mid : r = mid;
		}

		cout << fixed << setprecision(6) << min((ld) w/2.0, (l + r) / 2.0) << '\n';
	}
	cin.ignore(2); return 0;
}