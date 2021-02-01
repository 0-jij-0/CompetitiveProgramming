#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

vector<vector<int>> dp;
vector<string> v;

int main() {
	int H, W; cin >> H >> W; v.resize(H);
	for (auto &x : v) { cin >> x; }
	dp.resize(H, vector<int>(W, 0));
	dp[0][0] = 1; for(int i = 0; i < H; i++) for (int j = 0; j < W; j++) if((i || j) && v[i][j] == '.')
			dp[i][j] = ((i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0)) % mod;
	cout << dp[H - 1][W - 1] << '\n'; cin.ignore(2); return 0;
}