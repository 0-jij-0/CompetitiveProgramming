#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k; cin >> n >> k >> s;
		ll res = 0; string cur = s.substr(0, n / 2);

		for (int i = 0; i < n / 2; i++) {
			int rem = n / 2 - i - 1, w = cur[i] - 'a';
			res = (res + w * power(k, rem)) % mod;
		}

		string rcur = cur; char M = s[n / 2];
		reverse(rcur.begin(), rcur.end());
		if (n % 2 == 0) { res += (cur + rcur) < s; }
		else {
			int w = M - 'a'; res = (res * k + w);
			res += (cur + string(1, M) + rcur) < s;
		}
		cout << "Case #" << t << ": " << res % mod << '\n';
	}
	cin.ignore(2); return 0;
}