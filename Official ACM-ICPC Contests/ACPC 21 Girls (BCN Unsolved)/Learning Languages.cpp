#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

string s, p1, p2;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll findHash(const string& t, int l, int r) {
	ll res = 0; for (int i = l; i < r; i++)
		res = (res * 26 + t[i] - 'a') % mod; 
	return res;
}

int main() {
	freopen("poet.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> s >> p1 >> p2; int n = (int)s.size();
		int n1 = (int)p1.size(), n2 = (int)p2.size();
		ll h1 = findHash(p1, 0, n1), h = findHash(s, 0, n1);
		int i = n1; ll R = power(26, n1 - 1);
		while (h1 != h && i != n) {
			ll dec = (R * (s[i - n1] - 'a')) % mod;
			h = (h - dec + mod) % mod;
			h = (h * 26 + s[i++] - 'a') % mod;
		}
		if (i == n) { cout << 0 << '\n'; continue; }
		if (n - i < n2) { cout << 0 << '\n'; continue; }

		i -= n1; ll h2 = findHash(p2, 0, n2); h = findHash(s, i, i + n2);
		int j = i + n2, res = 0; R = power(26, n2 - 1); 
		
		while (j != n) {
			ll dec = (R * (s[j - n2] - 'a')) % mod;
			h = (h - dec + mod) % mod;
			h = (h * 26 + s[j++] - 'a') % mod;
			if (h2 == h && j >= i + n1) { res = j - i; }
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}