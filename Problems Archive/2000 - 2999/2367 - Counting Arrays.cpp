#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int SVSZ = 300001;

int spf[SVSZ]; vector<int> primes;

void buildSieve() {
	spf[0] = spf[1] = 1;
	for (int i = 2; i < SVSZ; i++) {
		if (spf[i] == 0) { primes.push_back(i);	spf[i] = i; }
		for (int j = 0; j < int(primes.size()) && primes[j] <= spf[i] && i * primes[j] < SVSZ; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	buildSieve(); primes.push_back(1 << 30);
	ll n, m; cin >> n >> m; ll ans = m % mod;

	ll cur = m, all = m %= mod, res = 0;
	for (int i = 2, j = 0; i <= n; i++) {
		if (i == primes[j]) { cur /= primes[j++]; }
		ans = (ans * (cur % mod)) % mod; all = (all * m) % mod;
		res = (res + (all - ans + mod)) % mod;
	}
	
	cout << res << '\n';
}