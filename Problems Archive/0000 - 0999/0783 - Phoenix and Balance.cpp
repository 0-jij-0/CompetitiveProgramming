#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a = 0, b = 0, i = 1;
		for (int j = 0; j < (n - 1) / 2; j++) { a |= i; i <<= 1; }
		for (int j = 0; j < n / 2; j++) { b |= i; i <<= 1; }
		cout << 2*(a | i) - 2*b << endl;
	}
	cin.ignore(2); return 0;
}