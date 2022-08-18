#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		if (k & 1) {
			cout << "YES\n";
			for (int i = 1; i <= n; i += 2)
				cout << i << ' ' << i + 1 << '\n';
		}
		else if ((k >> 1) & 1) {
			cout << "YES\n"; int cur = 1;
			for (int i = 4; i <= n; i += 4, cur += 2)
				cout << cur << ' ' << i << '\n';
			for (int i = 2; i <= n; i += 4, cur += 2)
				cout << i << ' ' << cur << '\n';
		}
		else { cout << "NO\n"; }
	}
}