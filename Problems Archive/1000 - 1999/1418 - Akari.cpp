#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
vector<vector<bool>> L, R, U, D;

int main() {
	int h, w, n, m; cin >> h >> w >> n >> m; 
	v.resize(h, vector<int>(w, 0));
	L.resize(h, vector<bool>(w, 0));
	R.resize(h, vector<bool>(w, 0));
	U.resize(h, vector<bool>(w, 0));
	D.resize(h, vector<bool>(w, 0));

	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		v[--x][--y] = 1;
	}
	for (int j = 0; j < m; j++) {
		int x, y; cin >> x >> y;
		v[--x][--y] = 2;
	}

	for (int i = 0; i < h; i++) {
		int j = 0, k = 0, cL = 2;
		while (k != w) {
			if (v[i][j] == 2) { cL = 2; j++; k++; continue; }
			if (v[i][j] == 1) {
				R[i][j] = 1; L[i][j] = 1;
				cL = 1; j++; k++; continue;
			}
			if (v[i][k] == 0) { k++; continue; }
			for (int x = j; x < k; x++) {
				L[i][x] = (cL == 1);
				R[i][x] = (v[i][k] == 1);
			}
			j = k;
		}
		for (int x = j; x < w; x++) L[i][x] = (cL == 1);
	}

	for (int j = 0; j < w; j++) {
		int i = 0, k = 0, cU = 2;
		while (k != h) {
			if (v[i][j] == 2) { cU = 2; i++; k++; continue; }
			if (v[i][j] == 1) {
				U[i][j] = 1; D[i][j] = 1;
				cU = 1; i++; k++; continue;
			}
			if (v[k][j] == 0) { k++; continue; }
			for (int x = i; x < k; x++) {
				U[x][j] = (cU == 1);
				D[x][j] = (v[k][j] == 1);
			}
			i = k;
		}
		for (int x = i; x < h; x++) U[x][j] = (cU == 1);
	}

	int res = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			res += L[i][j] || R[i][j] || U[i][j] || D[i][j];

	cout << res << '\n';
	cin.ignore(2); return 0;
}