#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; int res = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (!(i & (n - 1 - i))) { res ^= x; }
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}