#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		if (n > m) { swap(n, m); }
		if (m == 1) { cout << 0 << '\n'; continue; }
		cout << (n == 1 ? 1 : 2) << '\n';
	}
	cin.ignore(2); return 0;
}