#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll power(ll x, ll N) {
	ll res = 1;
	for (; N; N >>= 1, x = (x * x) % mod)
		if (N & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		string X, Y; int ones = 0;
		int n; cin >> n >> X >> Y;
		for (int i = 0; i < n; i++)
			ones += (X[i] != Y[i]);

		vector<ll> A(n), B(n), DP(n + 1);
		if (n > 1) { A[1] = 1; B[1] = ((n - 1) * modInv(n)) % mod; }
		for (int i = 2; i < n; i++) {
			ll denum = ((n - i * B[i - 1]) % mod + mod) % mod;
			B[i] = ((n - i) * modInv(denum)) % mod;
			A[i] = ((n + i * A[i - 1]) % mod + mod) % mod;
			A[i] = (A[i] * modInv(denum)) % mod;
		}
		DP[n] = ((1 + A[n - 1]) * modInv(1 - B[n - 1] + mod)) % mod;
		for (int i = n - 1; i >= ones; i--)
			DP[i] = (A[i] + B[i] * DP[i + 1]) % mod;
		cout << DP[ones] << '\n';
	}
}