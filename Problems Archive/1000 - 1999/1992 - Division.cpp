#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int x; cin >> x; cout << "Division ";
		if (x < 1400) { cout << 4 << '\n'; continue; }
		if (x < 1600) { cout << 3 << '\n'; continue; }
		if (x < 1900) { cout << 2 << '\n'; continue; }
		cout << 1 << '\n';
	}

	cin.ignore(2); return 0;
}