#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; bool ok = false;
		for (int i = 0; i <= n / 2020; i++) {
			if ((n - (i * 2020)) % 2021 == 0) { ok = true; break; }
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}