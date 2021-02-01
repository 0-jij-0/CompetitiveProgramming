#include <iostream>
#include <string>
using namespace std;

int DP[101][101];
int longFrom[101][101];

int run(int a[101][101], int c, int r, int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }

	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, max = 1;

	if (i > 0 && a[i - 1][j] < a[i][j]) {
		a1 = 1 + run(a, c, r, i - 1, j); max = a1;
	}
	if (j > 0 && a[i][j - 1] < a[i][j]) {
		a2 = 1 + run(a, c, r, i, j - 1); max = (max > a2) ? max : a2;
	}
	if (i + 1 < r && a[i + 1][j] < a[i][j]) {
		a3 = 1 + run(a, c, r, i + 1, j); max = (max > a3) ? max : a3;
	}
	if (j + 1 < c && a[i][j + 1] < a[i][j]) {
		a4 = 1 + run(a, c, r, i, j + 1); max = (max > a4) ? max : a4;
	}

	DP[i][j] = max;
	return max;
}

int max(int a[101][101], int c, int r) {
	int m = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			m = (m > a[i][j]) ? m : a[i][j];
		}
	}
	return m;
}

int longestRun(int a[101][101], int c, int r) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			DP[i][j] = -1;
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			longFrom[i][j] = run(a, c, r, i, j);
		}
	}
	return max(longFrom, c, r);
}

int main() {
	int N; cin >> N;
	int a[101][101];
	for (int i = 0; i < N; i++) {
		string s = ""; int c, r;
		cin >> s >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> a[i][j];
			}
		}
		cout << s + ": " << longestRun(a, c, r) << endl;
	}
	cin.ignore(2);
	return 0;
}

