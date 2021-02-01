#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 998244353;
ll n, m, L, R;

ll power(ll x, ll n) {
	if (n == 0) { return 1; }
	ll ans = power(x, n / 2);
	ans *= ans; ans %= mod;
	if (n & 1) { return (ans * x) % mod; }
	return ans;
}

int main() {
	cin >> n >> m >> L >> R;
	ll res = 1;
	if (L == R) { cout << 1 << endl; cin.ignore(2); return 0; }
	if (n*m % 2) {
		cout << power(R - L + 1, n*m) << endl;
		cin.ignore(2); return 0;
	}

	R -= L; ll o = (R + 1) / 2, e = R - o + 1;
	ll x = power(e + o, n*m), y = power(e - o, n*m);
	ll modinv2 = (mod + 1) / 2;

	cout << (((x + y) % mod) * modinv2) % mod << endl;
	cin.ignore(2); return 0;
}