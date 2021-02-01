#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
const ll inv2 = 500000004;

vector<ll> fact(301, 1);
ll dp[301][301][2];

int l;
ll cycles(int x) { return x == 2 ? fact[x - 1] : (fact[x - 1] * inv2) % mod; }
ll paths(int x) { return x == 1 ? fact[x] : (fact[x] * inv2) % mod; }
ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}
ll modInv(ll n) { return power(n, mod - 2); }
ll nChooseK(int n, int k) {
	ll num = fact[n];
	ll denum = (fact[n - k] * fact[k]) % mod;
	return (num * modInv(denum)) % mod;
}

ll countGraphs(int nodes, int edges, bool L) {
	if (nodes < edges) { return 0; }
	if (edges == 0) { return L; }
	if (dp[nodes][edges][L] != -1) { return dp[nodes][edges][L]; }

	ll res = countGraphs(nodes - 1, edges, L || l == 1);
	for (int i = 2; i <= min(nodes, l); i++) {
		if (edges < i - 1) { break; }
		ll count = nChooseK(nodes - 1, i - 1);

		ll P = (count * paths(i)) % mod;
		P = (P * countGraphs(nodes - i, edges - i + 1, L || i == l)) % mod;
		res = (res + P) % mod;

		if (edges < i) { break; }
		ll C = (count * cycles(i)) % mod;
		C = (C * countGraphs(nodes - i, edges - i, L || i == l)) % mod;
		res = (res + C) % mod;
	}
	return dp[nodes][edges][L] = res;
}

int main() {
	for (int i = 2; i <= 300; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	int n, m; cin >> n >> m >> l;
	fill(dp[0][0], dp[0][0] + 2 * 301 * 301, -1);
	cout << countGraphs(n, m, 0) << '\n';
	cin.ignore(2); return 0;
}