#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n, k; cin >> n >> k;
		ll total = (n * (n - 1)) >> 1;
		
		ll l = 1, r = n - 1; while (l != r) {
			ll mid = (l + r) >> 1;
			ll check = ((n - mid) * (n - mid - 1)) >> 1;
			(check + k <= total) ? r = mid : l = mid + 1;
		}

		k -= (l - 1) * n - ((l * (l - 1)) >> 1);
		cout << l << ' ' << l + k << '\n';
	}

	cin.ignore(2); return 0;
}