#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n, a, b; cin >> n >> a >> b;
		if (a == b && a == n) { cout << "Yes\n"; continue; }
		cout << (a + b < n - 1 ? "Yes" : "No") << '\n';
	}
}