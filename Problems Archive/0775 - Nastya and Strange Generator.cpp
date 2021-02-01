#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v, idx;
priority_queue<pair<int, int>> pq;

struct DSU {
	vector<int> rank, parent, nex;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
		iota(nex.begin(), nex.end(), 1);
	}

	int find(const int u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; v.resize(n); idx.resize(n); while (!pq.empty()) { pq.pop(); }
		for (auto &x : v) { cin >> x; x--; }
		for (int i = 0; i < n; i++) { idx[v[i]] = i; }
		for (int i = 0; i < n; i++) { pq.push({ 1, i }); }
		DSU dsu(n); bool b = true;
		for (int i = 0; i < n; i++) {
			while (v[pq.top().second] < i) { pq.pop(); }
			int id = idx[i]; if (dsu.size(id) != pq.top().first) { b = false; break; }
			if (dsu.find(id) != dsu.find(n - 1)) { 
				int nextID = id + 1 + dsu.size(id + 1) - 1;
				dsu.merge(id, id + 1); pq.push({ dsu.size(id), nextID });
			}
		}
		cout << (b ? "Yes" : "No") << endl;
	}
	cin.ignore(2); return 0;
}