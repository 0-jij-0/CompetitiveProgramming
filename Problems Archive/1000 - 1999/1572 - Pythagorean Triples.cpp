#include <iostream>
using namespace std;

int sqrtInt(int n) {
	int l = 0, r = 46340;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		mid * mid <= n ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int s = sqrtInt(2 * n - 1);
		cout << ((s + 1) >> 1) - 1 << '\n';
	}
	cin.ignore(2); return 0;
}