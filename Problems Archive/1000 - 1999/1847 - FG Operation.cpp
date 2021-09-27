#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<int> v;
vector<vector<int>> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	dp.resize(n, vector<int>(10));
	for (auto& x : v) { cin >> x; }
	dp[0][v[0]] = 1;

	for(int i = 0; i < n - 1; i++) for (int j = 0; j < 10; j++) {
		dp[i + 1][(j + v[i + 1]) % 10] = (dp[i + 1][(j + v[i + 1]) % 10] + dp[i][j]) % mod;
		dp[i + 1][(j * v[i + 1]) % 10] = (dp[i + 1][(j * v[i + 1]) % 10] + dp[i][j]) % mod;
	}

	for (int i = 0; i < 10; i++)
		cout << dp[n - 1][i] << '\n';

	cin.ignore(2); return 0;
}