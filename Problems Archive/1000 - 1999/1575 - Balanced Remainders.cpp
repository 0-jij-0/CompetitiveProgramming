#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; int r = n / 3;
		int c[3] = { 0, 0, 0 };
		while (n--) { int x; cin >> x; c[x % 3]++; }

		int res = 0;
		if (c[0] > r) { res += c[0] - r; c[1] += c[0] - r; c[0] = r; }
		if (c[1] > r) { res += c[1] - r; c[2] += c[1] - r; c[1] = r; }
		if (c[2] > r) { res += c[2] - r; c[0] += c[2] - r; c[2] = r; }
		if (c[0] > r) { res += c[0] - r; c[1] += c[0] - r; c[0] = r; }
		if (c[1] > r) { res += c[1] - r; c[2] += c[1] - r; c[1] = r; }
		if (c[2] > r) { res += c[2] - r; c[0] += c[2] - r; c[2] = r; }
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}