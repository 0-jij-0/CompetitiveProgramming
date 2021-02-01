#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank;
	vector<int> parent;

	DSU() {}
	DSU(int n) {
		rank.resize(n, 1);
		parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(int u, int v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	int size(int u) {
		return rank[find(u)];
	}
};

DSU dsu[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n; dsu[0] = dsu[1] = DSU(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y, c; cin >> x >> y >> c;
		x--; y--; dsu[c].merge(x, y);
	}
	long long res = 0;
	for (int i = 0; i < n; i++) {
		res += (long long)dsu[0].size(i) * dsu[1].size(i) - 1;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}