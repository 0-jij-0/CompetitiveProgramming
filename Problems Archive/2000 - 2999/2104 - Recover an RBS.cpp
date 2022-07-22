#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;

bool isValidParenthesis(string& s) {
	int pref = 0;
	for (char& c : s) {
		c == '(' ? pref++ : pref--;
		if (pref < 0) return false;
	}
	return pref == 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> s; int n = (int)s.size();
		vector<int> pref(n, 0); int openP = 0, closedP = 0;
		for (int i = 0; i < n; i++)	if (s[i] != '?') {
			(s[i] == '(' ? openP : closedP)++;
		}
		openP = (n / 2 - openP); closedP = (n / 2 - closedP);

		if (!closedP || !openP) { cout << "YES\n"; continue; }

		bool b = true;
		for (int i = 0; i < n; i++) if (s[i] == '?') {
			if (openP > 1) { s[i] = '('; openP--; continue; }
			if (openP && b) { s[i] = ')'; b = false; continue; }
			if (openP) { s[i] = '('; openP = 0; continue; }
			s[i] = ')';
		}

		cout << (isValidParenthesis(s) ? "NO" : "YES") << '\n';
	}
}