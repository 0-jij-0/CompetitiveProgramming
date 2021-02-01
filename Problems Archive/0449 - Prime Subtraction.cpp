#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		long long x, y; cin >> x >> y;
		cout << (((x - y) > 1) ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}