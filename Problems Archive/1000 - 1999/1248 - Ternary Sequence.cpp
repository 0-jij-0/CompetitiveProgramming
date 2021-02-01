#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int x1, y1, z1; cin >> x1 >> y1 >> z1;
		int x2, y2, z2; cin >> x2 >> y2 >> z2;
		int f = min(z1, y2); z1 -= f; y2 -= f;
		int s = min(z1, z2); z1 -= s; z2 -= s;
		s = min(x1, z2); x1 -= s; z2 -= s;

		cout << 2 * (f - z2) << endl;
	}
	cin.ignore(2); return 0;
}