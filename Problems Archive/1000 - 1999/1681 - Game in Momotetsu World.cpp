#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int dp[2001][2001];
vector<string> v;

int main() {
	int h, w; cin >> h >> w; v.resize(h);
	for (auto& x : v) { cin >> x; }

	dp[h - 1][w - 1] = 0;
	for(int i = h - 1; i >= 0; i--)
		for(int j = w - 1; j >= 0; j--)
			if (i != h - 1 || j != w - 1) {
				int t = (i + j) & 1;
				int D = (i != h - 1 && v[i + 1][j] == '+') ? 1 : -1;
				int R = (j != w - 1 && v[i][j + 1] == '+') ? 1 : -1;

				int a = (i != h - 1) ? D - dp[i + 1][j] : -(1 << 20);
				int b = (j != w - 1) ? R - dp[i][j + 1] : -(1 << 20);

				dp[i][j] = max(a, b);
			}

	if (dp[0][0] == 0) { cout << "Draw" << '\n'; }
	else cout << (dp[0][0] < 0 ? "Aoki" : "Takahashi") << '\n';
	cin.ignore(2); return 0;
}