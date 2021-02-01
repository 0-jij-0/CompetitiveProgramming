#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long n, k; cin >> n >> k;
		long long x = n - k * k;
		cout << (x >= 0 && x % 2 == 0 ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}