#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define v vector

v<v<v<char>>> grid;
v<v<char>> lS, fS;
v<v<int>> satRow;

struct point { 
	int x, y, z; point() {}
	point(int _x, int _y, int _z) :
		x(_x), y(_y), z(_z) {}
};

ostream &operator <<(ostream &os, point &p) {
	os << p.x << ' ' << p.y << ' ' << p.z << '\n';
	return os;
}

v<v<char>> frontShadow(int n, int m, int h) {
	v<v<char>> res(n, v<char>(m, '0'));
	for(int i =0; i < n; i++)
		for (int j = 0; j < m; j++)
			for(int k = 0; k < h; k++)
				if (grid[i][j][k] - '0') { res[i][j]++; break; }
	return move(res);
}

v<v<char>> leftShadow(int n, int m, int h) {
	v<v<char>> res(n, v<char>(h, '0'));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < h; j++)
			for (int k = 0; k < m; k++)
				if (grid[i][k][j] - '0') { res[i][j]++; break; }
	return move(res);
}

bool eqV(v<v<char>> &v1, v<v<char>> &v2, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (v1[i][j] != v2[i][j])
				return false;
	return true;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, h; cin >> n >> m >> h;
	grid.resize(n, v<v<char>>(m, v<char>(h, '1')));
	fS.resize(n, v<char>(m)); lS.resize(n, v<char>(h));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> fS[i][j];
			if (fS[i][j] == '0') for (int k = 0; k < h; k++) {
				grid[i][j][k] = '0';
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < h; j++) {
			cin >> lS[i][j];
			if (lS[i][j] == '0') for (int k = 0; k < m; k++) {
				grid[i][k][j] = '0';
			}
		}
	v<v<char>> temp1 = leftShadow(n, m, h), temp2 = frontShadow(n, m, h);
	if (!eqV(lS, temp1, n, h)) { cout << -1 << endl; return 0; }
	if (!eqV(fS, temp2, n, m)) { cout << -1 << endl; return 0; }
	vector<point> maxPoint;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < h; k++)
				if (grid[i][j][k] == '1')
					maxPoint.push_back(point(i, j, k));

	satRow.resize(n, v<int>(h, 0)); vector<point> minPoint;
	for (int i = 0; i < n; i++) {
		int minJ = -1;
		int bb = count(fS[i].begin(), fS[i].end(), '1');
		int aa = count(lS[i].begin(), lS[i].end(), '1');
		for (int j = 0; j < m; j++) {
			if (fS[i][j] == '0') { continue; }
			if (minJ == -1) { minJ = j; }
			bool add = true;
			for (int k = 0; k < h; k++) {
				if (lS[i][k] == '0') { continue; }
				if (satRow[i][k] && aa >= bb) { continue; }
				if (add) { bb--; add = false; }
				if (!satRow[i][k]) { aa--; satRow[i][k] = 1; }
				minPoint.push_back(point(i, j, k));
				if (aa <= bb) { break; }
			}
		}
	}
	cout << maxPoint.size() << '\n';
	for (auto &x : maxPoint) { cout << x; }
	cout << minPoint.size() << '\n';
	for (auto &x : minPoint) { cout << x; }
	cin.ignore(2); return 0;
}