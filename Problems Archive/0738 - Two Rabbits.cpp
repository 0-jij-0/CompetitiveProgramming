#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int x, y, a, b; cin >> x >> y >> a >> b;
		int t = (y - x) / (a + b);
		cout << ((y - x) % (a + b) ? -1 : t) << endl;
	}
	cin.ignore(2); return 0;
}