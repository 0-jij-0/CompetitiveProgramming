#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
int a[4][4] = { {8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14} };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n; g.resize(n);
	for (int i = 0; i < n; i++) { g[i].resize(n); }

	for (int i = 0; i < (n / 4); i++)
		for (int j = 0; j < (n / 4); j++)
			for (int k = 0; k < 4; k++)
				for (int l = 0; l < 4; l++)
					g[i * 4 + k][j * 4 + l] = a[k][l] + ((n / 4)*i + j) * 16;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j];
			if (j + 1 != n) { cout << ' '; }
		}
		cout << endl;
	}
	cin.ignore(2); return 0;
}