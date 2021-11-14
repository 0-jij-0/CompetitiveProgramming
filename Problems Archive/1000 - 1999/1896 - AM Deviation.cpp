#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll a, b, c; cin >> a >> b >> c;
		ll d = abs(a + c - (b << 1));
		cout << (d % 3 != 0) << '\n';
	}
	cin.ignore(2); return 0;
}