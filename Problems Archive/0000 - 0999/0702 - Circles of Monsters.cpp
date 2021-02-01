#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n; vector<ll> a(n), b(n);
		for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; }
		ll first = 1ll << 62, more = 0;
		for(int i = 0; i < n; i++) {
			ll x = max(0ll, a[(i + 1) % n] - b[i]);
			more += x; first = min(first, a[(i + 1) % n] - x);
		}
		cout << first + more << '\n';
	}
	cin.ignore(2); return 0;
}