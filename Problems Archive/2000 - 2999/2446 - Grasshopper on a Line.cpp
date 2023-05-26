#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int x, k; cin >> x >> k;
		if (x % k) { cout << 1 << '\n' << x << '\n'; continue; }
		cout << 2 << '\n' << 1 << ' ' << x - 1 << '\n';
	}
}