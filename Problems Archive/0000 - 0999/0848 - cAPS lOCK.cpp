#include <iostream>
#include <string>
using namespace std;

bool isUpper(char &c) { return c >= 'A' && c <= 'Z'; }

bool check(string &s) {
	for(int i = 1; i < (int)s.size(); i++)
		if (!isUpper(s[i])) { return false; }
	return true;
}

void invert(string &s) {
	s[0] = isUpper(s[0]) ? s[0] - 'A' + 'a' : s[0] - 'a' + 'A';
	for (int i = 1; i < (int)s.size(); i++)
		s[i] = s[i] - 'A' + 'a';
}

int main() {
	string s; cin >> s;
	if (!check(s)) { cout << s << endl; }
	else { invert(s); cout << s << endl; }
	cin.ignore(2); return 0;
}