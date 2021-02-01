#include <iostream>
#include <string>
using namespace std;

string DP[1000001][2];

string game(int *a, int n, int &m, bool b, string &s1, string &s2) {
	if (DP[n][b] != "") return DP[n][b];

	for (int i = 0; i < m; i++) {
		if (a[i] <= n) {
			string s = game(a, n - a[i], m, !b, s1, s2);
			if (s == ((b == 0) ? s2 : s1)) {
				DP[n][b] = (b == 0) ? s2 : s1;
				DP[n][!b] = (b == 0) ? s1 : s2;
				return DP[n][b];
			}
		}
	}
	DP[n][b] = (b == 0) ? s1 : s2;
	DP[n][!b] = (b == 0) ? s2 : s1;
	return DP[n][b];
}

int main() {
	DP[0][0] = "Stan wins"; DP[0][1] = "Ollie wins";
	string s1 = "Stan wins"; string s2 = "Ollie wins";
	int n; cin >> n;
	while (!cin.fail()) {
		for (int i = 1; i < n + 1; i++) { DP[i][0] = ""; DP[i][1] = ""; }
		int m; cin >> m;
		int *a = new int[m];
		for (int i = 0; i < m; i++) { cin >> a[i]; }
		int j = 0;
		while (j < n) {
			string s = game(a, j, m, true, s1, s2);
			j++;
		}
		cout << game(a, n, m, true, s1, s2) << endl;
		cin >> n;
		delete[] a;
	}
	cin.ignore(2);
	return 0;
}