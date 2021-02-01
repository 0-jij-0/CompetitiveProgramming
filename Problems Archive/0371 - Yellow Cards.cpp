#include <iostream>
using namespace std;

int main() {
	int a1, a2, k1, k2; cin >> a1 >> a2 >> k1 >> k2;
	int n; cin >> n; int max, min;
	if (k1 < k2) {
		int x = n / k1;
		if (x <= a1) { max = x; }
		else { int m = n - a1 * k1; max = a1 + m / k2; }
		int y = n - a1 * (k1 - 1) - a2 * (k2 - 1);
		min = (y < 0) ? 0 : y;
	}
	else {
		int x = n / k2;
		if (x <= a2) { max = x; }
		else { int m = n - a2 * k2; max = a2 + m / k1; }
		int y = n - a1 * (k1 - 1) - a2 * (k2 - 1);
		min = (y < 0) ? 0 : y;
	}
	cout << min << ' ' << max << endl;
	cin.ignore(2); return 0;
}