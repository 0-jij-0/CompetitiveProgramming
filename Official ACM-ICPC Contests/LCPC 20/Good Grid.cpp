#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
	freopen("grid.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	v.resize(n, vector<int>(m));
	for (auto& x : v) for (auto& y : x) cin >> y;

	if (m % 2) { cout << "NO" << '\n'; return 0; }

	bool ok = true; for (auto& x : v) {
		int c = count(x.begin(), x.end(), 0);
		if (abs(m / 2 - c) > 1) { ok = false; break; }
	}

	cout << (ok ? "YES" : "NO") << '\n';
}