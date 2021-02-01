#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int a[9] = { 1, 3, 6, 10, 15, 21, 28, 36, 45 };

int fact(ll n) {
	int res = 0;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i) { continue; }
		int p = 0; while (n % i == 0) { n /= i; p++; }
		res += upper_bound(a, a + 9, p) - a;
	}
	return res + (n != 1);
}

int main() {
	ll n; cin >> n;
	cout << fact(n) << '\n';
	cin.ignore(2); return 0;
}