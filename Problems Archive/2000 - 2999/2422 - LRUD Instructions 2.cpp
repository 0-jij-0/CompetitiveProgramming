#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; string s; cin >> n >> s;
	set<pair<int, int>> vis = { {0, 0} };
	int x = 0, y = 0; bool rep = false;
	for (char c : s) {
		if (c == 'R') ++x; else if (c == 'L') --x;
		if (c == 'U') ++y; else if (c == 'D') --y;
		if (vis.count({ x, y })) rep = true; vis.insert({ x, y });
	}

	cout << (rep ? "Yes" : "No") << '\n';
}