#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <string>
#include <set>
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

vector<string> v;

int main() {
	freopen("zamalek.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T; while (T--) {
		int X, K, N, M; cin >> X >> K >> N >> M;
		v.resize(N); for (auto& x : v) cin >> x;

		DSU dsu(N * M); for(int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (v[i][j] == '.') {
				if (i && v[i - 1][j] == '.') dsu.merge(i * M + j, (i - 1) * M + j);
				if (j && v[i][j - 1] == '.') dsu.merge(i * M + j, i * M + j - 1);
			}

		set<int> components;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) if (v[i][j] == '.')
				components.insert(dsu.find(i * M + j));

		int res = 0; for (auto& x : components)
			res += dsu.size(x) / K;

		cout << min(res, X) * K << '\n';
	}

}