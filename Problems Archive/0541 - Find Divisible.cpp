#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int l, r; cin >> l >> r;
		cout << l << ' ' << 2 * l << endl;
	}
	cin.ignore(2); return 0;
}