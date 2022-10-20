#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
		}
		cout << (m < n ? "YES" : "NO") << '\n';
	}
}