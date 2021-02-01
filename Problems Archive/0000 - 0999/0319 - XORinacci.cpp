#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, n; cin >> a >> b >> n;
		n %= 3; int x = a ^ b;
		if (n == 0) { cout << a << endl; }
		else if (n == 1) { cout << b << endl; }
		else { cout << x << endl; }
	}
	cin.ignore(2); return 0;
}