#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, x, m; cin >> n >> x >> m;
		int L = x, R = x;
		while (m--) {
			int l, r; cin >> l >> r;
			if ((L >= l && L <= r) || (R >= l && R <= r)) {
				L = min(l, L); R = max(r, R);
			}
		}
		cout << R - L + 1 << endl;
	}
	cin.ignore(2); return 0;
}