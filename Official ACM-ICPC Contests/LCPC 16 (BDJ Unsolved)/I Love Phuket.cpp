#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> v, d; int r, c;
int di[4] = { 1, -1, 0, 0 };
int dj[4] = { 0, 0, 1, -1 };

bool check(int K) {
	queue<pair<int, int>> q; 
	vector<vector<int>> d(r, vector<int>(c, -1));
	q.push({ 0, 0 }); d[0][0] = 0;

	while (!q.empty()) {
		pair<int, int> p = q.front(); q.pop();
		int& i = p.first, & j = p.second;
		if (i == r - 1 && j == c - 1) { return true; }

		for (int k = 0; k < 4; k++) {
			if (i + di[k] < 0 || i + di[k] >= r) { continue; }
			if (j + dj[k] < 0 || j + dj[k] >= c) { continue; }
			if (d[i + di[k]][j + dj[k]] != -1) { continue; }
			if (v[i + di[k]][j + dj[k]] - d[i][j] - 1 < K) { continue; }
			d[i + di[k]][j + dj[k]] = 1 + d[i][j];
			q.push({ i + di[k], j + dj[k] });
		}
	}
	return false;
}

int maxHeight() {
	int L = 0, R = v[0][0];
	while (L != R) {
		int mid = (L + R + 1) >> 1;
		check(mid) ? L = mid : R = mid - 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; while (n--) {
		cin >> r >> c; v.clear();
		v.resize(r, vector<int>(c));
		for (auto& x : v) for (auto& y : x) cin >> y;

		int res = maxHeight();
		if (!res) cout << "impossible" << '\n';
		else cout << res << '\n';
	}

	cin.ignore(2); return 0;
}