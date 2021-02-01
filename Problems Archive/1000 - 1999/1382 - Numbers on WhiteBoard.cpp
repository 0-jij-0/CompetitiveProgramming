#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; int i = 2, j = n;
		if (n == 2) {
			cout << 2 << '\n';
			cout << 1 << ' ' << 2 << '\n';
		}
		else {
			cout << 2 << '\n';
			cout << n << ' ' << n - 2 << '\n';
			cout << n - 1 << ' ' << n - 1 << '\n';
			n--; while (n != 2) {
				cout << n << ' ' << n - 2 << '\n';
				n--;
			}
		}
	}
	cin.ignore(2); return 0;
}