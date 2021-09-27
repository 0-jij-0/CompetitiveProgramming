#include <iostream>
using namespace std;
typedef long long ll;

ll toBase10(ll x, ll k) {
	ll res = 0, mult = 1;
	while (x) {
		res += ((x % 10) * mult);
		x /= 10; mult *= k;
	}
	return res;
}

int main() {
	ll k, a, b; cin >> k >> a >> b;
	cout << toBase10(a, k) * toBase10(b, k) << '\n';
}