#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<ll> fact(1000001, 1);

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll choose(int n, int k) {
	ll denum = (fact[n - k] * fact[k]) % mod;
	return (fact[n] * power(denum, mod - 2)) % mod;
}

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2; i <= 1000000; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	int n; cin >> n >> s; bool ok = true;
	int k = 0; for (char& c : s) {
		c == '(' ? k++ : k--;
		if (k < 0) { ok = false; break; }
	}
	if (n % 2 || !ok) { cout << 0 << '\n'; return 0; }
	n = ((n - ((int)s.size() - k)) / 2) - k;
	if (n < 0) { cout << 0 << '\n'; return 0; }

	ll scale = ((k + 1) * power(n + k + 1, mod - 2)) % mod;
	ll res = (scale * choose(2 * n + k, n)) % mod;
	cout << res << '\n';
	cin.ignore(2); return 0;
}