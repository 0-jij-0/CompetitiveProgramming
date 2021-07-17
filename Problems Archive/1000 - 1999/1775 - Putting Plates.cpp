#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> construct(int i, int j, int h, int w) {
	vector<vector<int>> v(h, vector<int>(w, 0)); int cnt = 1;
	v[i][j] = 1; for (int k = 0; k < w; k++) {
		if (v[0][k] || v[1][k]) { continue; }
		if (k && v[0][k - 1]) { continue; }
		if (k && v[1][k - 1]) { continue; }
		if (k != w - 1 && v[0][k + 1]) { continue; }
		if (k != w - 1 && v[1][k + 1]) { continue; }
		v[0][k] = 1; cnt++;
	}
	for (int k = 0; k < h; k++) {
		if (v[k][0] || v[k][1]) { continue; }
		if (k && v[k - 1][0]) { continue; }
		if (k && v[k - 1][1]) { continue; }
		if (k != h - 1 && v[k + 1][1]) { continue; }
		if (k != h - 1 && v[k + 1][0]) { continue; }
		v[k][0] = 1; cnt++;
	}
	for (int k = 0; k < w; k++) {
		if (v[h - 1][k] || v[h - 2][k]) { continue; }
		if (k && v[h - 1][k - 1]) { continue; }
		if (k != w - 1 && v[h - 1][k + 1]) { continue; }
		if (k && v[h - 2][k - 1]) { continue; }
		if (k  != w - 1 && v[h - 2][k + 1]) { continue; }
		v[h - 1][k] = 1; cnt++;
	}
	for (int k = 0; k < h; k++) {
		if (v[k][w - 1] || v[k][w - 2]) { continue; }
		if (k && v[k - 1][w - 1]) { continue; }
		if (k && v[k - 1][w - 2]) { continue; }
		if (k != h - 1 && v[k + 1][w - 2]) { continue; }
		if (k != h - 1 && v[k + 1][w - 1]) { continue; }
		v[k][w - 1] = 1; cnt++;
	}
	v[0].push_back(cnt); return move(v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int h, w; cin >> h >> w;
		vector<vector<int>> a = construct(0, 0, h, w);
		vector<vector<int>> b = construct(0, 1, h, w);
		vector<vector<int>> c = construct(1, 0, h, w);

		if (a.front().back() < b.front().back()) { swap(a, b); }
		if (a.front().back() < c.front().back()) { swap(a, c); }
		a.front().pop_back();
		for (auto& x : a) { for (auto& y : x) cout << y; cout << '\n'; }
		cout << '\n';
	}
	cin.ignore(2); return 0;
}