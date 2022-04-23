#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; n--; m--;
		if (n == 0 || m == 0) {
			cout << (max(n, m) <= 1 ? max(n, m) : -1) << '\n'; continue;
		}
		int fence = min(n, m) << 1;
		int rem = abs(n - m) * 2 - (abs(n - m) & 1);
		cout << fence + rem << '\n';
	}

	cin.ignore(2); return 0;
}