#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x1, y1; cin >> x1 >> y1;
	int x2, y2; cin >> x2 >> y2;

	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);

	cout << max(dx, dy) << endl;
	cin.ignore(2); return 0;
}