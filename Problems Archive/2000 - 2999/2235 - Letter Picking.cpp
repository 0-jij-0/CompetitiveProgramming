#include <iostream>
#include <string>
using namespace std;

int DP[2000][2000]; string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> s; int n = (int)s.size();
		for (int i = 0; i < n - 1; i++)
			DP[i][i + 1] = (s[i] != s[i + 1]);

		for(int len = 4; len <= n; len += 2)
			for (int i = 0; i + len - 1 < n; i++) {
				int j = i + len - 1;
				int LL = DP[i + 2][j], LR = DP[i + 1][j - 1], RR = DP[i][j - 2];

				int o1 = (LL > 0) ? 1 : (LL ? -1 : (s[i] == s[i + 1] ? 0 : s[i] < s[i + 1]));
				int o2 = (LR > 0) ? 1 : (LR ? -1 : (s[i] == s[j] ? 0 : s[i] < s[j]));
				int L = min(o1, o2);

				int o3 = (LR > 0) ? 1 : (LR ? -1 : (s[j] == s[i] ? 0 : s[j] < s[i]));
				int o4 = (RR > 0) ? 1 : (RR ? -1 : (s[j] == s[j - 1] ? 0 : s[j] < s[j - 1]));
				int R = min(o3, o4);

				DP[i][j] = max(L, R);
			}

		cout << (DP[0][n - 1] > 0 ? "Alice" : (DP[0][n - 1] ? "Bob" : "Draw")) << '\n';
	}
}