#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool check(ll x) {
	ll less = 0; for (int i = 1; i <= n; i++)
		less += min((x - 1) / i, n);

	return less <= ((n * n) >> 1);
}

ll find_middle() {
	ll l = 1, r = n * n;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		check(mid) ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	cin >> n; cout << find_middle() << '\n';
}