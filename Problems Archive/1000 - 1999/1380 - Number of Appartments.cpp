#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		if (n < 3 || n == 4) { cout << -1 << '\n'; continue; }
		if (n % 3 == 0) { cout << n / 3 << ' ' << 0 << ' ' << 0 << '\n'; continue; }
		if (n % 3 == 1) { cout << (n - 6) / 3 << ' ' << 0 << ' ' << 1 << '\n'; continue; }
		cout << (n - 3) / 3 << ' ' << 1 << ' ' << 0 << '\n';
	}
	cin.ignore(2); return 0;
}