#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			(x == 1 ? a : b)++;
		}
		if (a % 2) { cout << "NO" << '\n'; }
		else if (a == 0 && b % 2) { cout << "NO" << '\n'; }
		else { cout << "YES" << '\n'; }
	}
	cin.ignore(2); return 0;
}