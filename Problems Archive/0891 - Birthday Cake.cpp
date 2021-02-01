#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int w, h, k; cin >> w >> h >> k;
		vector<vector<int>> chips2D(w, vector<int>(h));
		for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++) {
				char c; cin >> c; chips2D[i][j] = (c == 'C');
			}

		for (int i = 1; i < h; i++) { chips2D[0][i] += chips2D[0][i - 1]; }
		for (int i = 1; i < w; i++) { chips2D[i][0] += chips2D[i - 1][0]; }
		for (int i = 1; i < w; i++)
			for (int j = 1; j < h; j++)
				chips2D[i][j] += chips2D[i - 1][j] + chips2D[i][j - 1] - chips2D[i - 1][j - 1];

		int res = 1000;
		for (int i1 = 0; i1 < w; i1++)
			for (int j1 = 0; j1 < h; j1++)
				for (int i2 = i1; i2 < w; i2++)
					for (int j2 = j1; j2 < h; j2++) {
						int area = (i2 - i1 + 1) * (j2 - j1 + 1);
						if (area >= res) { continue; }
						int ans = chips2D[i2][j2];
						if (i1) { ans -= chips2D[i1 - 1][j2]; }
						if (j1) { ans -= chips2D[i2][j1 - 1]; }
						if (i1 && j1) { ans += chips2D[i1 - 1][j1 - 1]; }
						if (ans != k) { continue; }
						res = area;
					}

		cout << (res == 1000 ? -1 : res) << endl;
	}
	cin.ignore(2); return 0;
}