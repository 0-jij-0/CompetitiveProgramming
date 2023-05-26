#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		int dx = 0, dy = 0; bool ok = false;
		for (char c : s) {
			if (c == 'U' || c == 'D') dy += (c == 'U' ? 1 : -1);
			if (c == 'L' || c == 'R') dx += (c == 'R' ? 1 : -1);
			if (dx == 1 && dy == 1) { ok = true; break; }
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
}