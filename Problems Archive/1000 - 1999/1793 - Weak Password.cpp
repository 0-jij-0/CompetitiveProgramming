#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s;
	if (count(s.begin(), s.end(), s[0]) == 4) {
		cout << "Weak" << '\n'; cin.ignore(2); return 0;
	}

	for (char& c : s) c -= '0';
	bool ok = true;
	if (s[1] != (s[0] + 1) % 10) { ok = false; }
	if (s[2] != (s[1] + 1) % 10) { ok = false; }
	if (s[3] != (s[2] + 1) % 10) { ok = false; }

	cout << (ok ? "Weak" : "Strong") << '\n';
	cin.ignore(2); return 0;
}