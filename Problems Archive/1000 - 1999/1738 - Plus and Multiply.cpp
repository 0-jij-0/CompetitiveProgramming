#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n, a, b; cin >> n >> a >> b;
		if (a == 1) { cout << ((n - 1) % b ? "No" : "Yes") << '\n'; }
		else {
			ll x = 1; bool ok = 0; while (x <= n) {
				if ((n - x) % b == 0) { ok = true; break; }
				x *= a;
			}
			cout << (ok ? "Yes" : "No") << '\n';
		}
	}
	cin.ignore(2); return 0;
}