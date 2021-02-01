#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

set<pair<int, int>> s;
set<int> non_vis;

struct graph {
	int n; graph(int _n) : n(_n) {}

	void bfs(int u) {
		queue<int> q; q.push(u); non_vis.erase(u);
		while (!q.empty()) {
			int f = q.front(); q.pop();
			set<int> era;
			for (auto &x : non_vis) {
				if (!s.count({ f, x })) {
					era.insert(x); q.push(x);
				}
			}
			for (auto &x : era) { non_vis.erase(x); }
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m; cin >> n >> m; graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		s.insert({ a - 1, b - 1 });
		s.insert({ b - 1, a - 1 });
	}
	for (int i = 0; i < n; i++) { non_vis.insert(i); }
	int res = 0;
	while (true) { 
		g.bfs(*non_vis.begin());
		if (non_vis.empty()) { break; }
		res++;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}