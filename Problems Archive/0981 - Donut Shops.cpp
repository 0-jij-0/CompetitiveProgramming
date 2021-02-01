#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b, c; cin >> a >> b >> c;
		int res1 = (a < c) ? 1 : -1;
		int res2 = (a * b > c) ? b : -1;
		cout << res1 << ' ' << res2 << '\n';
	}
	cin.ignore(2); return 0;
}