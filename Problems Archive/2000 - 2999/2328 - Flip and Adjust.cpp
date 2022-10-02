#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
bool DP[101][10001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s; v.resize(n);
	for (auto& [a, b] : v) cin >> a >> b;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= s; j++)
			DP[i][j] = (i == 0 && j == 0);

	for (int i = 1; i <= n; i++) {
		int a = v[i - 1].first, b = v[i - 1].second;
		for (int j = 0; j <= s; j++) {
			if (j >= a) { DP[i][j] = DP[i][j] || DP[i - 1][j - a]; }
			if (j >= b) { DP[i][j] = DP[i][j] || DP[i - 1][j - b]; }
		}
	}

	if (!DP[n][s]) { cout << "No\n"; return 0; }
	cout << "Yes\n"; string res = "";

	while (n) {
		int a = v[n - 1].first, b = v[n - 1].second;
		if (s >= a && DP[n - 1][s - a]) { res.push_back('H'); s -= a; --n; }
		else { res.push_back('T'); s -= b; --n; }
	}

	reverse(res.begin(), res.end());
	cout << res << '\n';
}