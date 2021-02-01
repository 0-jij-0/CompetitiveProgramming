#include <iostream>
using namespace std;

void chessboard(int b, int w) {
	int max = (b > w) ? b : w;
	int min = (b > w) ? w : b;
	if (max > 3 * min + 1) { cout << "NO" << endl; return; }
	cout << "YES" << endl;
	int x = 1, y = (b > w) ? 2 : 3;
	while (min != 0) {
		cout << x << ' ' << y << endl; max--;
		cout << x + 1 << ' ' << y << endl; min--;
		x += 2;
	}
	if (max != 0) { cout << x << ' ' << y << endl; max--; }
	x--;
	while (max != 0) {
		cout << x << ' ' << y + 1 << endl; max--;
		if (max == 0) { break; }
		cout << x << ' ' << y - 1 << endl; max--;
		x -= 2;
	}
	return;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int b, w; cin >> b >> w;
		chessboard(b, w);
	}
	cin.ignore(2); return 0;
}