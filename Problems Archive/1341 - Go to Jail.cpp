#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; bool ok = false; int c = 0;
	for (int i = 0; i < n; i++) {
		int d1, d2; cin >> d1 >> d2;
		if (d1 != d2) { c = 0; continue; }
		c++; if (c == 3) { ok = true; }
	}
	cout << (ok ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}