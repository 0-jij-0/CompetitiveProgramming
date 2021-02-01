#include <iostream>
#include <vector>
#include <numeric>
#include <queue>
using namespace std;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) {
		rank.resize(n, 1); parent.resize(n);
		iota(parent.begin(), parent.end(), 0);
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

vector<int> v, on, res;
priority_queue<pair<int, int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; v.resize(n); 
	on.resize(n, 0); res.resize(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i]; pq.push({ v[i], i });
	}
	int last = 0; DSU dsu(n);
	while (!pq.empty()) {
		int x = pq.top().first, idx = pq.top().second; pq.pop();
		on[idx] = 1;
		if (idx != 0 && on[idx - 1]) { dsu.merge(idx, idx - 1); }
		if (idx != n - 1 && on[idx + 1]) { dsu.merge(idx, idx + 1); }
		int cur = dsu.size(idx);
		for (int i = last + 1; i <= cur; i++)
			res[i] = x;
		last = max(last, cur);
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';

	cout << endl; cin.ignore(2); return 0;
}