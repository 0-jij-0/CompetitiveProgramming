#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b, c, r; cin >> a >> b >> c >> r;
		if (b < a) { swap(a, b); }
		int ri = min(b, c + r), le = max(a, c - r);
		if (le > ri) { le = ri; }
		cout << b - a - (ri - le) << endl;
	}
	cin.ignore(2); return 0;
}