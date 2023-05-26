#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll DP[200001]; string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n >> s; DP[0] = 0; ll sum = 1;
	for (int i = 1; i <= n; sum = (sum + DP[i++]) % mod)
		DP[i] = ((DP[i - 1] * 10) + sum * (s[i - 1] - '0')) % mod;
	cout << DP[n] << '\n';
}