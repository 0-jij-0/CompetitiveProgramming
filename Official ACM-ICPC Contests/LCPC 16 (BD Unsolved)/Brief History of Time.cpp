#include <iostream>
#include <string>
#include <map>
using namespace std;

void checkPalindrome(string& s, map<char, char>& m) {
	string t = s;
	int n = (int)s.size(); for (char& c : s)
		if (m.count(c)) c = m[c];

	int i = 0, j = n - 1; while (i < j)
		if (s[i++] != s[j--]) { cout << t << " NO\n"; return; }

	cout << t << " YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; while (n--) {
		int p; cin >> p; map<char, char> m;
		while (p--) {
			char a, b; cin >> a >> b;
			if (a < b) { swap(a, b); }
			m[a] = b;
		}
		int q; cin >> q; while (q--) {
			string s; cin >> s;
			checkPalindrome(s, m);
		}
	}
	cin.ignore(2); return 0;
}