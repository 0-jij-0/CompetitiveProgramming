#include <iostream>
using namespace std;

int n, a, x, b, y;

bool simulate() {
	while (a != x && b != y) {
		a++; b--;
		if (a > n) { a = 1; }
		if (b < 1) { b = n; }
		if (a == b) { return true; }
	}
	return false;
}

int main() {
	cin >> n >> a >> x >> b >> y;
	if (simulate()) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	return 0;
}