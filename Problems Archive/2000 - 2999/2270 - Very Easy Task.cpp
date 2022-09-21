#include <iostream>
using namespace std;
typedef long long ll;

ll minTime(int n, int x, int y) {
	if (x > y) { swap(x, y); }
	ll l = 0, r = 2 * 1000 * 1000 * 1000;

	while (l != r) {
		ll mid = (l + r) >> 1;
		(mid / x + (mid - x) / y < n) ? l = mid + 1 : r = mid;
	}

	return l;
}

int main() {
	int n, x, y; cin >> n >> x >> y;
	cout << minTime(n, x, y) << '\n';
}