#include <iostream>
#include <set>
#include <vector>
#include <numeric>
using namespace std;

vector<int> v, idx;

struct DSU {
	vector<int> parent;
	vector<set<int>> children;

	DSU(int n) {
		parent.resize(n); children.resize(n);
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { children[i].insert(v[i]); }
	}

	int size(int u) { return (int)children[parent[u]].size(); }

	bool merge(int u, int v) {
		u = parent[u]; v = parent[v]; if (u == v) { return false; }
		set<int> &min = (size(u) < size(v)) ? children[u] : children[v];
		set<int> &max = (size(u) < size(v)) ? children[v] : children[u];
		for (auto &x : min) { parent[idx[x]] = &max - &*children.begin(); max.insert(x); }
		min.clear(); return true;
	}
};

int main() {
	int n; cin >> n; v.resize(n + 2);
	idx.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a; v[i] = a; idx[a] = i;
	}
	DSU dsu(n + 2);
	dsu.children[0].clear(); dsu.children[n + 1].clear();
	v[0] = v[n + 1] = n + 1; long long res = 0;
	for (int i = 1; i <= n; i++) {
		int &id = idx[i];
		if (v[id - 1] < i) { dsu.merge(id, id - 1); }
		if (v[id + 1] < i) {
			int l = dsu.parent[id], r = dsu.parent[id + 1];
			set<int> &left = dsu.children[l], &right = dsu.children[r];
			set<int> &min = (dsu.size(l) < dsu.size(r)) ? left : right;
			set<int> &max = (dsu.size(l) < dsu.size(r)) ? right : left;
			for (auto &x : min) { res += max.count(i - x); }
			dsu.merge(id, id + 1);
		}
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}