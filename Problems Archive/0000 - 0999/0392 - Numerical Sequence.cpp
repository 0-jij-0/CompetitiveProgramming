#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int find_dig(ll k) {
	ll s = 0, count = 1, left = 1, right = 9;
	while (true) {
		if (s + (right - left + 1)*count >= k) { break; }
		s += (right - left + 1)*count;
		count++; left *= 10; right *= 10; right += 9;
	}
	ll x = (k - s - 1) / count, y = (k - s - 1) % count;
	ll num = left + x; string str = to_string(num);
	return str[(const unsigned int)y] - '0';
}

ll find_idx(ll k) {
	ll s = 0, count = 1, left = 1, right = 9;
	while (true) {
		ll r = right - left + 1ll;
		ll ps = r * (r + 1) / 2;
		if ((s*r + count * ps) >= k) { s += count; break; }
		k -= s * r + count * ps;
		s += r * count; count++; left *= 10ll; right *= 10ll; right += 9ll;
	}

	ll l = 0, r = 1ll << 30;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool b = (s*mid + (mid * (mid - 1) * count) / 2) < k;
		b ? l = mid : r = mid - 1;
	}
	k -= s * l + (l * (l - 1) * count) / 2;
	return k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--) {
		ll k; cin >> k; k = find_idx(k);
		cout << find_dig(k) << '\n';
	}
	cin.ignore(2); return 0;
}