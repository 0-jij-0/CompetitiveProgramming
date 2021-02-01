#include <iostream>
using namespace std;

int ans[2][2] = { {2, 1}, {1, 2} };

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a == b) { cout << 0 << endl; continue; }
		cout << ans[a > b][abs(a - b) % 2] << endl;
	}
	cin.ignore(2); return 0;
}