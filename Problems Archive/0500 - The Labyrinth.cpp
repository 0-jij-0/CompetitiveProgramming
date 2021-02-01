#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<pair<char, int>>> g;
vector<int> comp_size;
int n, m;

int bfs(int i, int j, int t) {
	queue<pair<int, int>> q; q.push({ i, j });
	g[i][j].second = t; int res = 1;

	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		int &ci = p.first, &cj = p.second;
		if (ci != 0 && g[ci - 1][cj].first != '*' && g[ci - 1][cj].second == -1) {
			res++; q.push({ ci - 1, cj }); g[ci - 1][cj].second = t;
		}
		if (cj != 0 && g[ci][cj - 1].first != '*' && g[ci][cj - 1].second == -1) {
			res++; q.push({ ci, cj - 1 }); g[ci][cj - 1].second = t;
		}
		if (ci != n - 1 && g[ci + 1][cj].first != '*' && g[ci + 1][cj].second == -1) {
			res++; q.push({ ci + 1, cj }); g[ci + 1][cj].second = t;
		}
		if (cj != m - 1 && g[ci][cj + 1].first != '*' && g[ci][cj + 1].second == -1) {
			res++; q.push({ ci, cj + 1 }); g[ci][cj + 1].second = t;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	g.resize(n, vector<pair<char, int>>(m));
	for(auto &x : g)
		for (auto &y : x) {
			char c; cin >> c;
			y.first = c; y.second = -1;
		}

	int t = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (g[i][j].first == '.' && g[i][j].second == -1) {
				comp_size.push_back(bfs(i, j, t)); t++;
			}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j].first == '.') { cout << '.'; continue; }
			set<int> comp; int ans = 1;
			if (i != 0 && g[i - 1][j].first == '.' && !comp.count(g[i - 1][j].second)) {
				ans += comp_size[g[i - 1][j].second]; comp.insert(g[i - 1][j].second);
			}
			if (j != 0 && g[i][j - 1].first == '.' && !comp.count(g[i][j - 1].second)) {
				ans += comp_size[g[i][j - 1].second]; comp.insert(g[i][j - 1].second);
			}
			if (i != n - 1 && g[i + 1][j].first == '.' && !comp.count(g[i + 1][j].second)) {
				ans += comp_size[g[i + 1][j].second]; comp.insert(g[i + 1][j].second);
			}
			if (j != m - 1 && g[i][j + 1].first == '.' && !comp.count(g[i][j + 1].second)) {
				ans += comp_size[g[i][j + 1].second]; comp.insert(g[i][j + 1].second);
			}
			cout << ans % 10;
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}