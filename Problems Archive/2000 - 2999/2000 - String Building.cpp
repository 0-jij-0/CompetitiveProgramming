#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s; int n = (int)s.size();
		if (s.size() == 1) { cout << "NO\n"; continue; }
		bool ok = s[0] == s[1] && s[n - 1] == s[n - 2];
		for(int i = 1; i < n - 1; i++)
			if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
				ok = false; break;
			}

		cout << (ok ? "YES" : "NO") << '\n';
	}

	cin.ignore(2); return 0;
}