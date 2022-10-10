#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000 * 1000 * 1000 + 7;

ll dp[62626];

int main() {
	int n; cin >> n; ll div2 = (mod + 1) >> 1;
	if (n % 4 == 1 || n % 4 == 2) { cout << "0\n"; return 0; }

	dp[0] = 1; int res = n * (n + 1) >> 2;
	for (int i = 1; i <= n; i++)
		for (int j = min(res - i, i * (i - 1) / 2); j >= 0; j--) 
			dp[j + i] = (dp[j + i] + dp[j]) % mod;

	cout << (dp[n * (n + 1) / 4] * div2) % mod << '\n';
}