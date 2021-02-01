#include <iostream>
#include <string>
using namespace std;

int dist(const string &s, const string &t) {
	int res = 0; int n = (int)s.size();
	for (int i = 0; i < n; i++)
		res += s[i] != t[i];
	return res;
}

int main() {
	string s, t; cin >> s >> t;
	if (dist(s, t) % 2) { cout << "impossible" << endl; }
	else {
		bool b = true; string p = s; int n = (int)p.size();
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) { continue; }
			b = !b; if (b) { p[i] = t[i]; }
		}
		cout << p << endl;
	}
	cin.ignore(2); return 0;
}