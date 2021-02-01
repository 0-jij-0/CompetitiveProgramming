#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int m; cin >> m; int xs = 0;
		for (int i = 0; i < m; i++) {
			int a; cin >> a; xs ^= a;
		}
		cout << (xs == 0) << endl;
	}
	cin.ignore(2); return 0;
}