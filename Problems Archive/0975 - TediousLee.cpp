#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SZ = 2000 * 1000 + 2;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[SZ];

ll count(int L) {
	if (L < 3) { return 0; }
	if (L < 5) { return 4; }
	if (dp[L] != -1) { return dp[L]; }

	ll one = count(L - 1);
	ll two = count(L - 2);
	ll three = count(L - 3);
	ll four = count(L - 4);

	ll A = (4 + two + 4 * three + 4 * four) % mod;
	ll B = (one + 2 * two) % mod;

	return dp[L] = max(A, B);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; fill(dp, dp + SZ, -1);
	ll x = count(SZ - 1);
	while (t--) {
		int n; cin >> n;
		cout << count(n) << '\n';
	}
	cin.ignore(2); return 0;
}