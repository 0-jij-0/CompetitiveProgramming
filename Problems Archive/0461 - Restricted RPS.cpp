#include <iostream>
#include <string>
using namespace std;

int n, a, b, c;
string s;

string check() {
	string res(s.size(), '0'); int w = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'R' && b) { res[i] = 'P'; b--; w++; continue; }
		if (s[i] == 'P' && c) { res[i] = 'S'; c--; w++; continue; }
		if (s[i] == 'S' && a) { res[i] = 'R'; a--; w++; continue; }
	}
	if (w < (n + 1) / 2) { return ""; }
	for (auto &x : res) {
		if (x != '0') { continue; }
		if (a) { x = 'R'; a--; continue; }
		if (b) { x = 'P'; b--; continue; }
		if (c) { x = 'S'; c--; continue; }
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> a >> b >> c >> s;
		string res = check();
		if (res == "") { cout << "NO" << endl; }
		else { cout << "YES" << endl << res << endl; }
	}
	cin.ignore(2); return 0;
}