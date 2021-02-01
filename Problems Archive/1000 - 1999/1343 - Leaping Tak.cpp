#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<int> L, R;
vector<ll> dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k; dp.resize(n + 1);
	L.resize(k); R.resize(k); dp[1] = 1; dp[0] = 0;
	for (int i = 0; i < k; i++) cin >> L[i] >> R[i];

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1]; for (int j = 0; j < k; j++) if(i - L[j] > 0) 
			dp[i] = (dp[i] + dp[i - L[j]] - dp[max(0, i - R[j] - 1)] + mod) % mod;
	}

	cout << (dp[n] - dp[n - 1] + mod) % mod << '\n';
	cin.ignore(2); return 0;
}