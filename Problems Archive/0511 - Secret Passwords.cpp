#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <set>
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<bool> b(26, false);
	int n; cin >> n; DSU dsu(26);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (char &c : s) { b[c - 'a'] = true; }
		for (int i = 1; i < (int)s.size(); i++)
			dsu.merge(s[i] - 'a', s[i - 1] - 'a');
	}

	set<int> s; int res = 0;
	for (int i = 0; i < 26; i++) {
		if (s.count(dsu.find(i))) { continue; }
		res += b[i]; s.insert(dsu.find(i));
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}