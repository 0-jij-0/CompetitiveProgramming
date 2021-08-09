#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

vector<string> v; int H, W;
struct state { int i, j, w; };

int dx[20] = {1, -1, 0, 0, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2};
int dy[20] = {0, 0, 1, -1, -1, 0, 1, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -1, 0, 1};

bool check(int i, int j, int k) {
	if (i + dx[k] < 0) { return false; }
	if (i + dx[k] >= H) { return false; }
	if (j + dy[k] < 0) { return false; }
	if (j + dy[k] >= W) { return false; }
	return true;
}

int bfs01() {
	vector<vector<bool>> vis(H, vector<bool>(W, 0));
	deque<state> L; L.push_back({0, 0, 0});

	while (!L.empty()) {
		state cur = L.front(); L.pop_front();
		int& i = cur.i, & j = cur.j, & w = cur.w;
		if (i == H - 1 && j == W - 1) { return w; }
		if (vis[i][j]) continue; vis[i][j] = true;

		for (int k = 0; k < 20; k++) if (check(i, j, k) && !vis[i + dx[k]][j + dy[k]]) {
			if (k < 4 && v[i + dx[k]][j + dy[k]] == '.') { L.push_front({ i + dx[k], j + dy[k], w }); continue; }
			L.push_back({ i + dx[k], j + dy[k], w + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> H >> W; v.resize(H);
	for (auto& x : v) { cin >> x; }
	cout << bfs01() << '\n';

	cin.ignore(2); return 0;
}