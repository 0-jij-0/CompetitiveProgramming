#include <iostream>
#include <string>
using namespace std;

string s, t;

int main() {
	cin >> s >> t; int n = (int)s.size();
	bool ok = (s == t); for (int i = 1; (i < n) && !ok; i++) {
		swap(s[i], s[i - 1]);
		if (s == t) { ok = true; break; }
		swap(s[i], s[i - 1]);
	}
	cout << (ok ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}