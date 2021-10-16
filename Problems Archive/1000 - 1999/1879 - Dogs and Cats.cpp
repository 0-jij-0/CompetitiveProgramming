#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

string s;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; ll d, c, m; cin >> n >> d >> c >> m >> s;
		int i = 0; while (i != n) {
			if (s[i] == 'D' && d) { d--; c += m; i++; continue; }
			if (s[i] == 'D') { break; }
			if (s[i] == 'C' && c) { c--; i++; continue; }
			if (s[i] == 'C') { break; }
		}
		bool b = find(s.begin() + i, s.end(), 'D') == s.end();
		cout << "Case #" << t << ": " << (b ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}