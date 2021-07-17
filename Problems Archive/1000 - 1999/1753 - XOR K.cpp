#include <iostream>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, res = 0; cin >> n; while (n--) {
		int x; cin >> x; res |= x;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}