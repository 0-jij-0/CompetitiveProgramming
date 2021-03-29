#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int cj, jc; cin >> cj >> jc >> s;
		int n = (int)s.size(), f = 0, l = n - 1;
		while (f != n && s[f] == '?') { f++; }
		while (l != -1 && s[l] == '?') { l--; }
		if (f == n) { cout << "Case #" << t << ": " << "0\n"; continue; }
		for (int i = 0; i < f; i++) s[i] = s[f];
		for (int i = n - 1; i > l; i--) s[i] = s[l];

		int i = 0, j = 0, cost = 0; while (j != n) {
			if (s[i] != '?') { i = j = j + 1; continue; }
			if (s[j + 1] == '?') { j++; continue; }
			if (s[i - 1] == s[j + 1]) { i = j = j + 1; continue; }
			cost += (s[i - 1] == 'C') ? cj : jc; i = j = j + 1;
		}
		for (i = 1; i < n; i++) if (s[i] != '?' && s[i - 1] != '?')
			if (s[i] != s[i - 1]) cost += (s[i] == 'C') ? jc : cj;

		cout << "Case #" << t << ": " << cost << '\n';
	}
	cin.ignore(2); return 0;
}