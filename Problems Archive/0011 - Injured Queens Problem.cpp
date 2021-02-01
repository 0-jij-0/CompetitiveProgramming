#include <iostream>
#include <string>
using namespace std;

long long DP[17][17];

long long queen(string s, int &n, int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i == n) return 1;
	
	if (s[i] != '?') {
		int m = 0;
		if (s[i] >= 'A') {
			m = s[i] - 'A' + 10;
		}
		else {
			m = s[i] - '0';
		}
		if (i == 1) {
			DP[i][j] = queen(s, n, i + 1, m);
			return DP[i][j];
		}
		if (j == m || j == m + 1 || j == m - 1) { return 0; }
		DP[i][j] = queen(s, n, i + 1, m);
		return DP[i][j];
	}

	if (i == 1) {
		long long a = 0;
		for (int k = 1; k < n; k++) {
			a = a + queen(s, n, i + 1, k);
		}
		DP[i][j] = a;
		return a;
	}
	long long b = 0;
	for (int k = 1; k < n; k++) {
		if (k != j && k != j - 1 && k != j + 1) {
			b = b + queen(s, n, i + 1, k);
		}
	}
	DP[i][j] = b;
	return b;
}

long long injQueen(string s) {
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			DP[i][j] = -1;
		}
	}
	s = " " + s;
	int n = s.size();
	return queen(s, n, 1, 0);
}

int main() {
	string s = ""; cin >> s;
	while (!cin.fail()) {		
		cout << injQueen(s) << endl;
		cin >> s;
	}
	return 0;
}