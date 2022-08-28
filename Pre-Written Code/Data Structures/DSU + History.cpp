#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

struct DSU {
	vector<int> parent;
	vector<vector<int>> children;
	vector<vector<pair<int, int>>> history;
	int TIME = 0;

	DSU(int n) : parent(n), children(n), history(n) {
		iota(parent.begin(), parent.end(), 0);
		for (int i = 0; i < n; i++) { children[i].push_back(i); }
	}

	int size(const int &u) { return (int)children[parent[u]].size(); }

	bool merge(int u, int v, const int &w) {
		u = parent[u]; v = parent[v]; if (u == v) { return false; }
		if (size(u) > size(v)) { swap(u, v); }
		for (auto &x : children[u]) {
			history[x].push_back({ TIME, w });
			parent[x] = v; children[v].push_back(x);
		}
		TIME++; children[u].clear(); return true;
	}

	int query(int u, int v) {
		if (history[u].size() > history[v].size()) { swap(u, v); }
		if (history[u].empty()) { return history[v].back().second; }

		int l = 0, r = history[u].size();
		while (l != r) {
			int mid = (l + r) >> 1;
			(history[u].rbegin() + mid)->first == (history[v].rbegin() + mid)->first ? l = mid + 1 : r = mid;
		}
		if (l == history[u].size()) { return (history[v].rbegin() + l)->second; }
		return max((history[v].rbegin() + l)->second, (history[u].rbegin() + l)->second);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

}