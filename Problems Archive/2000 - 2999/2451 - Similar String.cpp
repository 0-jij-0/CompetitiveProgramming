#include <bits/stdc++.h>
using namespace std;

map<char, char> m = { {'0', 'o'}, {'o', '0'}, {'1', 'l'}, {'l', '1'} };

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; string s, t; cin >> n >> s >> t;
	bool ok = true;
	for (int i = 0; i < n; i++) 
		if (s[i] != t[i] && (!m.count(s[i]) || m[s[i]] != t[i])) {
			ok = false; break;
		}
	cout << (ok ? "Yes" : "No") << '\n';
}