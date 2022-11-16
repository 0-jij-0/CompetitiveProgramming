#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n; 

    dp[0] = dp[1] = 1; dp[2] = dp[3] = 0;
    for (int i = 4; i <= n; i++) {
        ll dp1 = ((i + 1ll) * dp[i - 1]) % mod;
        ll dp2 = ((i - 2ll) * dp[i - 2]) % mod;
        ll dp3 = ((i - 5ll) * dp[i - 3]) % mod;
        ll dp4 = ((i - 3ll) * dp[i - 4]) % mod;
        dp[i] = ((dp1 - dp2 - dp3 + dp4) % mod + mod) % mod;
    }

    cout << dp[n] << '\n';
}