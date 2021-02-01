#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		int ans = 1 << 30, A = -1, B = -1, C = -1;
		for (int cA = 1; cA <= 2 * a; cA++) {
			for (int cB = cA; cB <= 2 * b; cB += cA) {
				int cC1 = cB * (c / cB), cC2 = cB * ((c + cB - 1) / cB);
				int cC = (c - cC1 < cC2 - c) ? cC1 : cC2;
				int res = abs(cA - a) + abs(cB - b) + abs(cC - c);
				if (ans > res) { ans = res;	A = cA;	B = cB;	C = cC;	}
			}
		}
		cout << ans << endl << A << " " << B << " " << C << endl;
	}
	cin.ignore(2); return 0;
}