#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; n /= 6;
		int l = 0, r = 1000; while (l != r) {
			int mid = (l + r) >> 1;
			if (mid * mid == n) { l = r = mid; break; }
			mid * mid < n ? l = mid + 1 : r = mid - 1;
		}
		cout << l << '\n';
	}
	cin.ignore(2); return 0;
}