#include <iostream>
using namespace std;

int main() {
	freopen("looking.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; int res = 0;
		while (n--) { int x; cin >> x; res |= x; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}