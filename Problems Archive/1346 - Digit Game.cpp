#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		if (n % 2) {
			bool r = false; int i = 0;
			while (i < n) {
				if (s[i] % 2) { r = true; break; }
				i += 2;
			}
			cout << (r ? "1" : "2") << '\n';
		}
		else {
			bool b = false; int i = 1;
			while (i < n) {
				if (s[i] % 2 == 0) { b = true; break; }
				i += 2;
			}
			cout << (b ? "2" : "1") << '\n';
		}
	}
	cin.ignore(2); return 0;
}