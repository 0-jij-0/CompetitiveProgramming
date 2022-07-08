#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		if (n & 1) { cout << -1 << '\n'; continue; }
		cout << n / 2 << ' ' << n / 2 << ' ' << 0 << '\n';
	}
}