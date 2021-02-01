#include <iostream>
using namespace std;

const int u = 24 * 60;

int main() {
	int t; cin >> t;
	while (t--) {
		int h, m; cin >> h >> m;
		cout << u - 60 * h - m << endl;
	}
	cin.ignore(2); return 0;
}