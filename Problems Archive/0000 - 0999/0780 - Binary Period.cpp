#include <iostream>
#include <string>
using namespace std;

bool period1(string &s) {
	char c = s[0];
	for (char &x : s) if (x != c) return false;
	return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (period1(s)) { cout << s << endl; continue; }
		string res(2 * s.size(), '0');
		for (int i = 0; i < res.size(); i += 2) { res[i] = '1'; }
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}