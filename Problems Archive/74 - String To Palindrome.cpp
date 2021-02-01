#include <iostream>
#include <string>
using namespace std;

int DP[1001][1001];

int DPmakePal(string &s, int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];

	if (s[i] == s[j]) { DP[i][j] = DPmakePal(s, i + 1, j - 1); return DP[i][j]; }

	int x = 1 + DPmakePal(s, i + 1, j);
	int y = 1 + DPmakePal(s, i, j - 1);
	int z = 1 + DPmakePal(s, i + 1, j - 1);

	int m = (x < y) ? x : y;
	DP[i][j] = (m < z) ? m : z;
	return DP[i][j];
}

void makePal(string &s) {

	for (unsigned int i = 0; i < s.size() + 1; i++) {
		for (unsigned int j = 0; j < s.size() + 1; j++) {
			if (i > j || i == j) { DP[i][j] = 0; }
			else { DP[i][j] = -1; }
		}
	}
	cout << DPmakePal(s, 0, s.size() - 1) << endl;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string s; cin >> s;
		cout << "Case " << i + 1 << ": "; makePal(s);
	}
	cin.ignore(2); return 0;
}