#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		string a(n, '0'), b(n, '0'); bool c = true;
		for (int i = 0; i < n; i++) {
			if (c && s[i] == '2') { a[i] = b[i] = '1'; continue; }
			if (c && s[i] == '1') { a[i] = '1'; b[i] = '0'; c = false; continue; }
			if (c && s[i] == '0') { a[i] = b[i] = '0'; continue; }
			b[i] = s[i];
		}
		cout << a << endl << b << endl;
	}
	cin.ignore(2); return 0;
}