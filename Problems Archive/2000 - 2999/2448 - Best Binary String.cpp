#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s; int n = (int)s.size();
		int i = 0, j = n - 1; bool rev = false;
		while (i <= j) {
			if (s[i] == '0' + rev) { i++; continue; }
			if (s[j] == '1' - rev) { j--; continue; }
			if (s[i] == '?' && s[j] == '?') {
				s[i++] = '0' + rev; s[j--] = '1' - rev; continue;
			}
			if (s[i] == '1' - rev && s[j] == '0' + rev) { rev ^= 1; continue; }
			if (s[i] == '?') { s[i] = '0' + rev; continue; }
			if (s[j] == '?') { s[j] = '1' - rev; continue; }
		}
		cout << s << '\n';
	}
}