#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int r, g, b; cin >> r >> g >> b;
		if (r < g) { swap(r, g); }
		if (r < b) { swap(r, b); }
		if (g < b) { swap(g, b); }
		if (r == g) { cout << b + (r - (b + 1) / 2) << endl; }
		else if (r - g >= b) { cout << b + g << endl; }
		else { b -= r - g; cout << b + (r - (b + 1) / 2) << endl; }
	}
	cin.ignore(2); return 0;
}