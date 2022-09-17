#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

int di[6] = {-1, -1, 0, 0, 1, 1};
int dj[6] = {-1, 0, -1, 1, 0, 1};
vector<vector<int>> v; int N;

bool check(int i, int j, int k) {
	if (i + di[k] < 0 || i + di[k] > 2000) return false;
	if (j + dj[k] < 0 || j + dj[k] > 2000) return false;
	return v[i + di[k]][j + dj[k]];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N; DSU dsu(2001 * 2001); v.resize(2001, vector<int>(2001, 0));
	int res = N; for (int x = 0; x < N; x++) {
		int i, j; cin >> i >> j; i += 1000; j += 1000;
		for (int k = 0; k < 6; k++) if (check(i, j, k))
			res -= dsu.merge(i * 2001 + j, (i + di[k]) * 2001 + j + dj[k]);
		v[i][j] = 1;
	}

	cout << res << '\n';
}