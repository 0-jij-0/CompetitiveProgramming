#include <iostream>
#include <cmath>
using namespace std;
typedef double ld;
const ld PI = 3.14159265358979323846264;

int main() {
	freopen("polygon.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int p; ld x; cin >> p >> x;
		if ((p + 0.0) / (4 * PI) < x) { cout << "KEE\n"; continue; }

		ld l = 1.0, r = 1e6;
		for (int i = 0; i < 100; i++) {
			ld mid = (l + r) / 2.0;
			ld y = (p + 0.0) / (4 * mid * tan(PI / mid));
			(y < x) ? l = mid : r = mid;
		}

		cout << (int)floor(l) << '\n';
	}

	cin.ignore(2); return 0;
}