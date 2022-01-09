#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

vector<ll> fact(5001, 1);

ll power(ll x, ll n) {
	ll res = 1; x %= mod;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll choose(int n, int k) {
	return (fact[n] * power(fact[k] * fact[n - k], mod - 2)) % mod;
}

ll dp[26][5001]; string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i <= 5000; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	cin >> s; int n = (int)s.size();
	vector<int> freq(26, 0);
	for (char& c : s) freq[c - 'a']++;

	for (int i = 0; i <= freq[0]; i++) dp[0][i] = 1;

	int pref = freq[0];
	for (int i = 1; i < 26; i++) {
		for(int a = 0; a <= pref; a++)
			for (int b = 0; b <= freq[i]; b++) {
				ll cont = (dp[i - 1][a] * choose(a + b, b)) % mod;
				dp[i][a + b] = (dp[i][a + b] + cont) % mod;
			}
		pref += freq[i];
	}

	int sum = 0; for (int i = 1; i <= 5000; i++)
		sum = (sum + dp[25][i]) % mod;
	cout << sum << '\n'; cin.ignore(2); return 0;
}