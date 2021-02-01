#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> umb;
vector<bool> rain;
int a, m, n;
int dp[2005][1005][2];

int min_fatigue(int i, int j, bool s) {
	if (dp[i][j][s] != -1) { return dp[i][j][s]; }
	if (i == a) { dp[i][j][s] = 0; return 0; }

	int res = -1;
	if (rain[i]) {
		int a = (umb[i]) ? umb[i] + min_fatigue(i + 1, i, 1) : -1;
		if (!s) { dp[i][j][s] = a; return a; }
		int b = umb[j] + min_fatigue(i + 1, j, 1);
		if (a == -1) { dp[i][j][s] = b; return b; }
		dp[i][j][s] = min(a, b); return min(a, b);
	}
	int a = (umb[i]) ? umb[i] + min_fatigue(i + 1, i, 1) : -1;
	int b = (s) ? umb[j] + min_fatigue(i + 1, j, 1) : -1;
	int c = min_fatigue(i + 1, j, 0);

	if (a == -1 && b == -1 && c == -1) { dp[i][j][s] = -1; return -1; }
	int m = c;
	if (a != -1) { m = (m != -1) ? min(a, m) : a; }
	if (b != -1) { m = (m != -1) ? min(m, b) : b; }
	dp[i][j][s] = m; return m;
}

int main() {
	cin >> a >> m >> n;

	for (int i = 0; i < a + 2; i++)
		for (int j = 0; j < a + 2; j++)
			dp[i][j][0] = dp[i][j][1] = -1;

	umb.resize(a + 1, 0); rain.resize(a + 1, false);
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		for (int j = l; j < r; j++) { rain[j] = true; }
	}
	map<int, int> map;
	for (int i = 0; i < n; i++) {
		int x, p; cin >> x >> p;
		if (map.find(x) == map.end()) { map[x] = p; }
		else { map[x] = min(map[x], p); }
	}
	for (auto a : map) { umb[a.first] = a.second; }

	cout << min_fatigue(0, 0, 0) << endl;
	cin.ignore(2); return 0;
}