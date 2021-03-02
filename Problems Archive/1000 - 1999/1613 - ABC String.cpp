#include <iostream>
#include <string>
using namespace std;

string s; int n;

bool check(char a, char b, char c) {
	string t = s; for (char& x : t)
		if (x == 'A') x = a;
		else if (x == 'B') x = b;
		else if (x == 'C') x = c;

	int p = 0; for (char& x : t)
		if (x == ')' && !p) return false;
		else { x == '(' ? p++ : p--; }
	return p == 0;
}

int main() {
	int t; cin >> t; while (t--) {
		cin >> s; n = (int)s.size();

		if (check('(', '(', ')')) { cout << "YES\n"; continue; }
		if (check('(', ')', '(')) { cout << "YES\n"; continue; }
		if (check('(', ')', ')')) { cout << "YES\n"; continue; }
		if (check(')', '(', '(')) { cout << "YES\n"; continue; }
		if (check(')', '(', ')')) { cout << "YES\n"; continue; }
		if (check(')', ')', '(')) { cout << "YES\n"; continue; }
		cout << "NO" << '\n';
	}
	cin.ignore(2); return 0;
}