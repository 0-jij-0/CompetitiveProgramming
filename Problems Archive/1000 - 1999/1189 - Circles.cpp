#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll a, b, d; cin >> a >> b >> d;
		cout << fixed << (d * d) / 2.0 << '\n';
	}
	cin.ignore(2); return 0;
}