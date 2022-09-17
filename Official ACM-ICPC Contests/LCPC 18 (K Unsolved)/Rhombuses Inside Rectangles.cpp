#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll choose2(ll x) {
	ll res = (x * (x - 1)) >> 1;
	return res % mod;
}

int main() {
	freopen("rect.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int W, H; cin >> W >> H;
		ll vertical = choose2((W + 1) >> 1) + choose2((W + 2) >> 1);
		ll horizontal = choose2((H + 1) >> 1) + choose2((H + 2) >> 1);
		cout << (vertical * horizontal) % mod << '\n';
	}
}