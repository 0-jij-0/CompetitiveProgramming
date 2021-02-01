#include <iostream>
using namespace std;
typedef long long ll;

int digSum(ll n) {
	int s = 0; 
	while (n) { s += n % 10; n /= 10; }
	return s;
}

int main() {
	int t; cin >> t; while (t--) {
		ll n; int s; cin >> n >> s;
		if (digSum(n) <= s) { cout << 0 << '\n'; continue; }
		ll mult = 1, res = 0; while (digSum(n) > s) {
			ll add = 10 - n % 10; n += add;
			res += add * mult; mult *= 10; n /= 10;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}