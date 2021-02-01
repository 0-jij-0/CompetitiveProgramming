#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> grid;
set<pair<int, int>> cur, nextCur;
vector<vector<pair<int, int>>> north, south, west, east;
vector<vector<bool>> still;
long long skillSum = 0;

void initialize(int r, int c) {
	grid.clear(); cur.clear(); nextCur.clear(); still.clear();
	north.clear(); south.clear(); east.clear(); west.clear();
	grid.resize(r, vector<int>(c));
	north.resize(r, vector<pair<int, int>>(c, { -1, -1 }));
	south.resize(r, vector<pair<int, int>>(c, { -1, -1 }));
	east.resize(r, vector<pair<int, int>>(c, { -1, -1 }));
	west.resize(r, vector<pair<int, int>>(c, { -1, -1 }));
	still.resize(r, vector<bool>(c, true)); skillSum = 0;
	for (auto &x : grid) for (auto &y : x) { cin >> y; skillSum += y; }
	for (int i = 0; i < r * c; i++) { cur.insert({ i / c, i % c }); }
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (i > 0) { north[i][j] = { i - 1, j }; }
			if (i < r - 1) { south[i][j] = { i + 1, j }; }
			if (j > 0) { west[i][j] = { i, j - 1 }; }
			if (j < c - 1) { east[i][j] = { i, j + 1 }; }
		}
}

int getAt(const pair<int, int> &p) { return (p.first == -1) ? 0 : grid[p.first][p.second]; }

void update(vector<vector<pair<int, int>>> &v, int i, int j) {
	if (i == -1) { return; }
	int xi = v[i][j].first, xj = v[i][j].second;
	while (xi != -1 && !still[xi][xj]) {
		int xxi = v[xi][xj].first, xxj = v[xi][xj].second;
		xi = xxi; xj = xxj;
	}
	v[i][j] = { xi, xj };
}

bool round() {
	bool keepGoing = false;
	for (auto &x : cur) {
		int i = x.first, j = x.second; if (!still[i][j]) { continue; }
		int ni = north[i][j].first, nj = north[i][j].second, si = south[i][j].first, sj = south[i][j].second;
		int wi = west[i][j].first, wj = west[i][j].second, ei = east[i][j].first, ej = east[i][j].second;
		int a = getAt(north[i][j]), b = getAt(south[i][j]), c = getAt(west[i][j]), d = getAt(east[i][j]);
		int y = (a != 0) + (b != 0) + (c != 0) + (d != 0), z = getAt(x);
		if (a + b + c + d <= y * z) { continue; }
		nextCur.erase({ i, j });
		if (ni != -1) { nextCur.insert({ ni, nj }); }
		if (si != -1) { nextCur.insert({ si, sj }); }
		if (wi != -1) { nextCur.insert({ wi, wj }); }
		if (ei != -1) { nextCur.insert({ ei, ej }); }
		skillSum -= z; still[i][j] = false; keepGoing = true;
	}
	cur = move(nextCur); nextCur.clear();
	for (auto &x : cur) {
		int i = x.first, j = x.second;
		update(north, i, j); update(south, i, j);
		update(west, i, j); update(east, i, j);
	}
	return keepGoing;
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int r, c; cin >> r >> c; initialize(r, c);
		long long res = 0ll; do { res += skillSum; } while (round());
		cout << "Case #" << t << ": " << res << endl;
	}
	cin.ignore(2); return 0;
}