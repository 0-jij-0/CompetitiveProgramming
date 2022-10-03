#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> rank, par;

	DSU(int n) : rank(n, 1), par(n) { iota(par.begin(), par.end(), 0); }

	int find(const int &u) { return par[u] == u ? u : (par[u] = find(par[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		if((u = find(u)) == (v = find(v))) return false;
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	par[v] = u;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}