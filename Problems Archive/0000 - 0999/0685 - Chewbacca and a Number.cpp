#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char inv(char &c) { return 9 - (c - '0') + '0'; }

int main() {
	string s; cin >> s; int n = s.size();
	s[0] = (s[0] == '9') ? '9' : min(s[0], inv(s[0]));
	for (int i = 1; i < n; i++) { s[i] = min(s[i], inv(s[i])); }
	cout << s << endl; cin.ignore(2); return 0;
}