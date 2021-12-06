#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	freopen("album.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n, k; cin >> n >> k;
		if (k == 1) { cout << -1 * (n != 1) << '\n'; continue; }

		ll res = (n = ((n + k - 1) / k));
		while (n >= k) { res += (n / k); n = (n / k) + (n % k); }
		cout << res + (n != 1) << '\n';
	}

	cin.ignore(2); return 0;
}