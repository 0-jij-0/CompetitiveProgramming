#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
#include <map>
using namespace std;

vector<int> c;

struct DSU {
	vector<int> parent;
	vector<map<int, int>> v;

	DSU(int n) : parent(n), v(n) {
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) v[i][c[i]] = 1;
	}

	int find(const int& u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }

	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) { return false; }
		if (v[a].size() < v[b].size()) { swap(a, b); }
		parent[b] = a;

		for (auto& x : v[b]) v[a][x.first] += x.second;
		v[b].clear(); return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q; c.resize(n);
	for (auto& x : c) { cin >> x; }

	DSU dsu(n); while (q--) {
		int t, a, b; cin >> t >> a >> b;
		if (t == 1) { dsu.merge(--a, --b); continue; }
		cout << dsu.v[dsu.find(--a)][b] << '\n';
	}
	cin.ignore(2); return 0;
}