#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> p;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; p.resize(n);
		for (auto& x : p) { cin >> x; }

		ll cur = p[0], res = 0; for (int i = 1; i < n; i++) {
			if ((p[i] * 100 + cur - 1) / cur > k) {
				ll l = cur, r = 1ll << 40;
				while (l != r) {
					ll mid = (l + r) >> 1;
					bool b = (p[i] * 100 + mid - 1) / mid > k;
					b ? l = mid + 1 : r = mid;
				}
				res += l - cur; cur = l;
			}
			cur += p[i];
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}