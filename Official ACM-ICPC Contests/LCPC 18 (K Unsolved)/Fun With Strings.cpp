#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

vector<ll> a, b;

int main() {
	freopen("fun.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q;
		string s, t; cin >> s; t = s;
		reverse(t.begin(), t.end());

		a.resize(n); b.resize(n);
		a[0] = s[0] - '0'; b[0] = t[0] - '0';
		for (int i = 1; i < n; i++) {
			a[i] = (a[i - 1] * 10 + s[i] - '0') % mod;
			b[i] = (b[i - 1] * 10 + t[i] - '0') % mod;
		}

		while (q--) {
			int l, r; cin >> l >> r; l--;
			int R = n - l, L = n - r;

			ll left = l ? a[l - 1] : 0;
			left = (left * power(10, n - l)) % mod;

			ll right = r == n ? 0 : a[r - 1];
			ll sub = (right * power(10, n - r)) % mod;
			right = right ? (a.back() - sub + mod) % mod : 0;

			sub = L ? (b[L - 1] * power(10, R - L)) % mod : 0;
			ll mid = (b[R - 1] - sub + mod) % mod; 
			mid = (mid * power(10, n - r)) % mod;

			cout << (left + mid + right) % mod << '\n';
		}
	}
	cin.ignore(2); return 0;
}