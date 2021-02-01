#include <iostream>
using namespace std;

int k, n, a, b;

int find_max(int left, int right) {
	if (left == right) { return left; }
	int mid = (left + right + 1) / 2;
	int charge = mid * a + (n - mid) * b;
	if (charge < k) { return find_max(mid, right); }
	return find_max(left, mid - 1);
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> k >> n >> a >> b;
		if (k / b < n) { cout << -1 << endl; continue; }
		if (k / b == n && k % b == 0) { cout << -1 << endl; continue; }
		int m = (k / a < n) ? k / a : n;
		cout << find_max(0, m) << endl;
	}
	cin.ignore(2); return 0;
}