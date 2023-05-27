#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> st;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m, h, k; string s;  
	cin >> n >> m >> h >> k >> s;
	while (m--) { int x, y; cin >> x >> y; st.insert({ x, y }); }

	int x = 0, y = 0; bool ok = true;
	for (int i = 0; i < n; i++) {
		h--; if (h < 0) { ok = false; break; }
		if (s[i] == 'R') { x++; }
		if (s[i] == 'L') { x--; }
		if (s[i] == 'U') { y++; }
		if (s[i] == 'D') { y--; }
		if (st.count({ x, y }) && h < k) { h = k; st.erase({ x, y }); }
	}
	cout << (ok ? "Yes" : "No") << '\n';
}