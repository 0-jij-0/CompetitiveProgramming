#include <iostream>
#include <string>
using namespace std;

string p = "abacaba";

bool check(string &s, int i) {
	int n = (int)s.size();
	for (int j = i; j < i + 7; j++)
		if (s[j] != p[j - i] && s[j] != '?') return false;
	string r = s; int res = 0;
	for (int j = i; j < i + 7; j++) { r[j] = p[j - i]; }
	for (int i = 0; i < n - 6; i++)
		res += r.substr(i, 7) == p;
	if (res != 1) { return false; }
	s = r; return true;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		int res = 0;
		for (int i = 0; i < n - 6; i++)
			res += s.substr(i, 7) == p;
		if (res > 1) { cout << "NO" << endl; continue; }
		if (res == 1) { 
			cout << "YES" << endl;
			for (char &c : s) { cout << (c == '?' ? 'z' : c); }
			cout << endl; continue;
		}
		int i = n - 7; while (i >= 0) { if (check(s, i)) { break; } i--; }
		if (i == -1) { cout << "NO" << endl; continue; }
		cout << "YES" << endl;
		for (char &c : s) { cout << (c == '?' ? 'z' : c); }
		cout << endl;
	}
	cin.ignore(2); return 0;
}