#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		if (a * d == c * b) { cout << "0\n"; continue; }
		if (a == 0 || c == 0) { cout << "1\n"; continue; }
		if (a * d < b * c) { swap(a, c); swap(b, d); }
		cout << 1 + ((a * d) % (b * c) != 0) << '\n';
	}
}