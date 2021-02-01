#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int dx = abs(x1 - x2), dy = abs(y1 - y2);
		if (dx == 0) { cout << dy << '\n'; }
		else if (dy == 0) { cout << dx << '\n'; }
		else { cout << dx + dy + 2 << '\n'; }
	}
	cin.ignore(2); return 0;
}