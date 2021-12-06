#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000*1000*1000+7;

ll dp[5001][5001];
vector<int> v;

ll power(ll x, ll n){
    ll res = 1;
    for (; n; n >>= 1, x = (x * x) % mod)
        if (n & 1) res = (res * x) % mod;
    return res;
}

int main() {
    freopen("polygon.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fill(dp[0], dp[0] + 5001*5001, 0);
    for(int i = 0; i < 5001; i++){dp[i][0] = 1;}

    int n; cin >> n; v.resize(n);
    for(auto &x : v) cin >> x;
    sort(v.begin(), v.end());

    for(int i = 1; i <= n; i++) for(int t = 1; t <= 5000; t++){
        dp[i][t] = dp[i - 1][t];
        if(t - v[i - 1] >= 0){dp[i][t] = (dp[i][t] + dp[i - 1][t - v[i - 1]]) % mod;}
    }

    for(int i = 0; i <= n; i++)
        for(int j = 1; j <= 5000; j++)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;

    ll res = 0; for(int i = 0; i < n; i++){
        ll cont = power(2, i);
        cont = (cont - dp[i][v[i]] + mod) % mod;
        res = (res + cont) % mod;
    }

    cout << res << '\n';
}
