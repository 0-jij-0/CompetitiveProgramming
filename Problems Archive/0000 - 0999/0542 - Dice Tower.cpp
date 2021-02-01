#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long x; cin >> x;
		if (x < 15) { cout << "NO" << endl; continue; }
		if (x % 14 == 0) { cout << "NO" << endl; continue; }
		if (x % 14 < 7) { cout << "YES" << endl; continue; }
		cout << "NO" << endl;
	}
	cin.ignore(2); return 0;
}