#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s; int n = 5; bool b = false;
	while (n--) { string t; cin >> t; b = b || t[0] == s[0] || t[1] == s[1]; }
	cout << (b ? "YES" : "NO") << endl; cin.ignore(2); return 0;
}