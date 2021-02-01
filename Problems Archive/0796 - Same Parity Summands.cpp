#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		if (k > n) { cout << "NO" << endl; continue; }
		if (n % 2 && (k % 2) == 0) { cout << "NO" << endl; continue; }
		if (n % 2 || !(k % 2)) {
			cout << "YES" << endl;
			while (k != 1) { cout << 1 << ' '; k--; n--; }
			cout << n << endl; continue;
		}
		if (n < 2 * k) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		while (k != 1) { cout << 2 << ' '; k--; n -= 2; }
		cout << n << endl;
	}
	cin.ignore(2); return 0;
}