#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		long long n; cin >> n; while (n % 2 == 0) { n >>= 1; }
		cout << (n == 1 ? "NO" : "YES") << '\n';
	}
	cin.ignore(2); return 0;
}