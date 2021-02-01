#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int b, p, f; cin >> b >> p >> f; b /= 2;
		int h, c; cin >> h >> c;
		if (h < c) {
			int s = min(f, b), cost = s * c;
			if (f < b) { b -= f; s = min(b, p); cost += s * h; }
			cout << cost << endl;
		}
		else {
			int s = min(p, b), cost = s * h;
			if (p < b) { b -= p; s = min(b, f); cost += s * c; }
			cout << cost << endl;
		}
	}
	cin.ignore(2); return 0;
}