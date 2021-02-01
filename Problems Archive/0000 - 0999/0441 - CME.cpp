#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n < 4) { cout << 4 - n << endl; }
		else { cout << n % 2 << endl; }
	}
	cin.ignore(2); return 0;
}