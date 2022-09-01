#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> fact(1000 * 1000 + 1);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	freopen("tennis.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fact[0] = 1; for (int i = 1; i <= 1000 * 1000; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	int t; cin >> t; while (t--) {
		int n; cin >> n; ll N = n;
		ll nC2 = (N * (N - 1)) >> 1, all = power(2, nC2);
		cout << (all - fact[n] + mod) % mod << '\n';		
	}

	cin.ignore(2); return 0;
}