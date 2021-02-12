#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll findRes(const ll &b, const ll &x) {
	ll l = 0, r = b - 1;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool check = (mid * b + mid) <= x;
		check ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll x, y; cin >> x >> y; y = min(y, x - 1);
		ll b = 2, res = 0; while (b <= y) {
			ll cur = findRes(b, x);
			res += cur; b++;
			if (cur != b - 2) { break; }
		}

		ll cur = findRes(b, x);	while (b <= y) {
			ll l = b, r = y; while (l != r) {
				ll mid = (l + r + 1) >> 1;
				bool check = (cur * mid + cur <= x);
				check ? l = mid : r = mid - 1;
			}
			res += (l - b + 1) * cur; 
			b = l + 1; cur = findRes(b, x);
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}