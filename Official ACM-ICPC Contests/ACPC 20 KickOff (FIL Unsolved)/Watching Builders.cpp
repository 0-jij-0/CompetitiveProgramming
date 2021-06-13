#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("box.in", "r", stdin);

	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		ll a = (n * (n + 1)) % mod;
		ll r = (a * (n + 2)) % mod;
		cout << r << '\n';
	}
	return 0;
}