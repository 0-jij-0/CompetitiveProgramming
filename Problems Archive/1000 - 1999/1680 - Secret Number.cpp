#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string s, string t) {
	for(char &c : t)
		if (s[c - '0'] == 'x') { return false; }
		else if (s[c - '0'] == 'o') { s[c - '0'] = '?'; }

	return find(s.begin(), s.end(), 'o') == s.end();
}

bool addOne(string& t) {
	if (t == "9999") { return false; }
	int c = 1, i = 0; while (c) {
		t[i] = (t[i] - '0' + 1) % 10 + '0';
		c = t[i] == '0'; i++;
	} return true;
}

int main() {
	string s; cin >> s; string t = "0000";
	int res = 0; do { res += check(s, t); } while (addOne(t));
	cout << res << '\n'; cin.ignore(2); return 0;
}