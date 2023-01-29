#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		if (n & 1) cout << -1 << '\n';
		else cout << n / 2 << ' ' << 1 << '\n';
	}
}