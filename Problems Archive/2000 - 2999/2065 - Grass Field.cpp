#include <iostream>
using namespace std;

int a[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> a[0] >> a[1] >> a[2] >> a[3];
		if (a[0] + a[1] + a[2] + a[3] == 0) { cout << 0 << '\n'; continue; }
		if (a[0] + a[2] + a[1] + a[3] == 4) { cout << 2 << '\n'; continue; }
		cout << 1 << '\n';
	}
}