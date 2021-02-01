#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n; int k = 2;
		while (n % ((1 << k) - 1)) { k++; }
		cout << n / ((1 << k) - 1) << endl;
	}
	cin.ignore(2); return 0;
}