#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> grid;

bool check(int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '.') {
				if (j == 0 || (j + 1) == n) { return false; }
				if (i > n - 3) { return false; }
				if (grid[i + 1][j] == '#') { return false; }
				grid[i + 1][j] = '#';
				if (grid[i + 2][j] == '#') { return false; }
				grid[i + 2][j] = '#';
				if (grid[i + 1][j - 1] == '#') { return false; }
				grid[i + 1][j - 1] = '#';
				if (grid[i + 1][j + 1] == '#') { return false; }
				grid[i + 1][j + 1] = '#';
			}
		}
	}
	return true;
}

int main() {
	int n; cin >> n; grid.resize(n);
	for (int i = 0; i < n; i++) { grid[i].resize(n); }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c; grid[i][j] = c;
		}
	}

	string res = (check(n)) ? "YES" : "NO";
	cout << res << endl;
	cin.ignore(2); return 0;
}