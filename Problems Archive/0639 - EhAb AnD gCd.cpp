#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int x; cin >> x;
		cout << 1 << ' ' << x - 1 << endl;
	}
	cin.ignore(2); return 0;
}