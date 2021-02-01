#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int a, b; cin >> a >> b;
		int d = abs(b - a);
		cout << (d % 10 != 0) + d / 10 << '\n';
	}
	cin.ignore(2); return 0;
}