#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c, n; cin >> a >> b >> c >> n;
		if (b < c) { swap(b, c); }
		if (a < b) { swap(a, b); }
		int x = a + b + c + n;
		if (x % 3) { cout << "NO" << endl; continue; }
		if (x / 3 < a) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
	}
	cin.ignore(2); return 0;
}