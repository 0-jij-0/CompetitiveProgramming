#include <iostream>
#include <string>
using namespace std;

bool isLower(char c) { return c <= 'z' && c >= 'a'; }
bool isUpper(char c) { return c <= 'Z' && c >= 'A'; }
bool isDigit(char c) { return c <= '9' && c >= '0'; }

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n >> s;
		bool upper = false, lower = false, digit = false, special = false;
		for (char c : s) {
			if (isLower(c)) { lower = true; continue; }
			if (isUpper(c)) { upper = true; continue; }
			if (isDigit(c)) { digit = true; continue; }
			special = true;
		}

		if (!lower) { s.push_back('a'); }
		if (!upper) { s.push_back('A'); }
		if (!digit) { s.push_back('0'); }
		if (!special) { s.push_back('&'); }
		if (s.size() < 7) { s += string(7 - (int)s.size(), '0'); }

		cout << "Case #" << t << ": " << s << '\n';
	}
}