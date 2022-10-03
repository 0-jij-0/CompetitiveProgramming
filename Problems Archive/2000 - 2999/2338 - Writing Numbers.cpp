#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll M, const ll& n) {
	ll res = 0, digit = 1, period = 10, y = M;
	while (y) {
		res += (M / period) * digit;
		ll last = (M % period) / digit;
		if (last > 1) { res += digit; }
		else if (last) { res += 1 + (M % digit); }
		digit *= 10; period *= 10; y /= 10;
	}
	return res <= n;
}

ll findLast(const ll& n) {
	ll L = 0, R = 1ll << 60;
	while (L != R) {
		ll M = (L + R + 1) >> 1;
		check(M, n) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	ll n; cin >> n;
	cout << findLast(n) << '\n';
}