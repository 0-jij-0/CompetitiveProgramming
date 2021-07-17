#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll fact[100001];

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

int main() {
	freopen("phone.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	fact[0] = 1; for (int i = 1; i <= 100000; i++)
		fact[i] = (fact[i - 1] * i) % mod;

	string s; cin >> s; ll res = 0, denum = 1;
	for (int i = 0; i < 10; i++) {
		int a, b; cin >> a >> b;
		res += b; denum = (denum * fact[b]) % mod;
	}
	res = (fact[res] * power(denum, mod - 2)) % mod;
	cout << res << '\n'; cin.ignore(2); return 0;
}