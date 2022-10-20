#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		for (int i = 0, x = 0; i < n; i++) cin >> x;
		cout << 3 * (10 - n) * (10 - n - 1) << '\n';
	}
}