#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int f = min(b, c / 2);
		b -= f; c -= 2 * f;
		int s = min(a, b / 2);
		cout << 3*(f + s) << endl;
	}
	cin.ignore(2); return 0;
}