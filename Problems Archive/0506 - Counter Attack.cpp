#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

set<pair<int, int>> s;
set<int> non_vis;
vector<vector<int>> res;

struct graph {
	int n; graph(int _n) : n(_n) {}

	void bfs(int u) {
		queue<int> q; q.push(u); non_vis.erase(u);
		res.emplace_back(vector<int>(1, u));
		while (!q.empty()) {
			int f = q.front(); q.pop();
			set<int> era;
			for (auto &x : non_vis) {
				if (!s.count({ min(f, x), max(f, x) })) {
					era.insert(x); q.push(x);
					res.back().push_back(x);
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
		int a, b; cin >> a >> b; a--; b--;
		s.insert({ min(a, b), max(a, b) });
	}
	for (int i = 0; i < n; i++) { non_vis.insert(i); }
	while (true) {
		g.bfs(*non_vis.begin());
		if (non_vis.empty()) { break; }
	}
	cout << res.size() << '\n';
	for (auto &x : res) {
		cout << x.size() << ' ';
		for (auto &y : x)
			cout << y + 1 << ' ';
		cout << '\n';
	}
	cin.ignore(2); return 0;
}