#include <iostream>
using namespace std;

int main() {
	freopen("gift.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		cout << n / 8 << ' ' << 7 * n / 8 << '\n';
	}
	cin.ignore(2); return 0;
}