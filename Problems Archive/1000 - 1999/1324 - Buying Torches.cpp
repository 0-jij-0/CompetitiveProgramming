#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll x, y, k; cin >> x >> y >> k;
		ll s = 1, S = (k * y + x - 2) / (x - 1);
		s += (x - 1) * S - k * y;
		cout << S + k + (k - s + x - 2) / (x - 1) << '\n';
	}
	cin.ignore(2); return 0;
}