#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m, res = 0; cin >> n >> m;
		int i = 31;	m++; while (--i >= 0) {
			if ((n & (1 << i)) == (m & (1 << i))) { continue; }
			if (n & (1 << i)) { break; }
			res |= 1 << i;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}