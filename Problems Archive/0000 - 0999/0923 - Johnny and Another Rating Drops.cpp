#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n; ll res = 0;
		while (n) { res += n; n >>= 1; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}