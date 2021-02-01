#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll a, b; cin >> a >> b; 
		if (a > b) { swap(a, b); }
		if (b >= 2 * a) { cout << a << endl; continue; }
		ll dif = b - a; b = a = a - dif; ll ans = dif;
		if (a > 1) { ans += 2 * (a / 3); a %= 3; }
		if (a == 2) { ans++; }
		cout << ans << endl;
	}
	cin.ignore(2); return 0;
}