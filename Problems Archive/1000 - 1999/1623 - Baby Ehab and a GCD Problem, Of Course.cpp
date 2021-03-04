#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	freopen("gcd.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll res = 0;
	int q; cin >> q; while (q--) {
		ll l, r; cin >> l >> r;
		if (l != r) { res = 1; }
		else { res = gcd(res, l); }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}