#include <iostream>
#include <string>
using namespace std;

string a, b;

int main() {
	int t; cin >> t; while (t--) {
		int n;; cin >> n >> b; a.resize(n, '0');
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (c == 0 && b[i] == '1') { a[i] = '1'; c = 2; continue; }
			if (c == 0) { a[i] = '1'; c = 1; continue; }
			if (c == 1 && b[i] == '1') { a[i] = '1'; c = 2; continue; }
			if (c == 1) { a[i] = '0'; c = 0; continue; }
			if (b[i] == '1') { a[i] = '0'; c = 1; continue; }
			a[i] = '1'; c = 1;
		}
		cout << a << '\n';
	}
	cin.ignore(2); return 0;
}