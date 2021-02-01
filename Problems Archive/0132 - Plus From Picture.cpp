#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> grid;
int row, col, w, h;

bool check(int i, int j) {
	bool finish = false;
	for (int k = j - 1; k >= 0; k--) {
		if (grid[i][k] == '*' && finish == false) { 
			if (k == 0) { finish = true; break; }
			continue;
		}
		if (grid[i][k] == '*' && finish == true) { return false; }
		if (grid[i][k] == '.' && finish == false) { finish = true; continue; }
		if (grid[i][k] == '.' && finish == true) { continue; }
	}
	if (!finish) { return false; }
	finish = false;
	for (int k = j + 1; k < w; k++) {
		if (grid[i][k] == '*' && finish == false) {
			if (k + 1 == w) { finish = true; break; }
			continue;
		}
		if (grid[i][k] == '*' && finish == true) { return false; }
		if (grid[i][k] == '.' && finish == false) { finish = true; continue; }
		if (grid[i][k] == '.' && finish == true) { continue; }
	}
	if (!finish) { return false; }
	finish = false;
	for (int k = i - 1; k >= 0; k--) {
		if (grid[k][j] == '*' && finish == false) {
			if (k == 0) { finish = true; break; }
			continue;
		}
		if (grid[k][j] == '*' && finish == true) { return false; }
		if (grid[k][j] == '.' && finish == false) { finish = true; continue; }
		if (grid[k][j] == '.' && finish == true) { continue; }
	}
	if (!finish) { return false; }
	finish = false;
	for (int k = i + 1; k < h; k++) {
		if (grid[k][j] == '*' && finish == false) { 
			if (k + 1 == h) { finish = true; break; }
			continue;
		}
		if (grid[k][j] == '*' && finish == true) { return false; }
		if (grid[k][j] == '.' && finish == false) { finish = true; continue; }
		if (grid[k][j] == '.' && finish == true) { continue; }
	}
	if (!finish) { return false; }
	row = i; col = j; return true;
}

bool plus_shape() {
	bool decided = false;
	for (int i = 1; i < h - 1; i++) {
		for (int j = 1; j < w - 1; j++) {
			bool b = grid[i][j] == '*'; if (!b) { continue; }
			b = grid[i - 1][j] == '*'; if (!b) { continue; }
			b = grid[i + 1][j] == '*'; if (!b) { continue; }
			b = grid[i][j - 1] == '*'; if (!b) { continue; }
			b = grid[i][j + 1] == '*'; if (!b) { continue; }
			b = check(i, j);
			if (b) { decided = true; continue; }
			return false;
		}
	}
	if (!decided) { return false; }
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (grid[i][j] == '*' && i != row && j != col) { return false; }
		}
	}
	return true;
}

int main() {
	cin >> h >> w; grid.resize(h);
	for (int i = 0; i < h; i++) { grid[i].resize(w); }
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) { cin >> grid[i][j]; }
	}
	bool b = plus_shape();
	if (b) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}