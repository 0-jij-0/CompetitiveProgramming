#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;
		ll l = 0, r = 1ll << 32;
		while (l != r) {
			ll mid = (l + r + 1) >> 1;
			ll x = n * mid;
			ll notDiv = x - (x / n);
			(notDiv >= k) ? r = mid - 1 : l = mid;
		}
		int x = n * l; k -= x - (x / n);
		cout << x + k << endl;
	}
	cin.ignore(2); return 0;
}