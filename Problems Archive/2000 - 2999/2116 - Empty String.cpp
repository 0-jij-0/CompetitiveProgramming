#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[500][500]; string s;
ll choose[260][260];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 260; i++) {
		choose[i][0] = choose[i][i] = 1; for (int j = 1; j < i; j++)
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
	}

	cin >> s; int n = (int)s.size();

	for (int len = 2; len <= n; len += 2)
		for (int i = 0; i + len - 1 < n; i++) {
			int j = i + len - 1; dp[i][j] = 0;
			for (int k = j - 1; k >= i; k -= 2) if (s[j] == s[k]) {
				ll cont = ((k > i ? dp[i][k - 1] : 1) * (k + 1 < j ? dp[k + 1][j - 1] : 1)) % mod;
				dp[i][j] = (dp[i][j] + cont * choose[len >> 1][(k - i) >> 1]) % mod;
			}
		}

	cout << dp[0][n - 1] << '\n';
}