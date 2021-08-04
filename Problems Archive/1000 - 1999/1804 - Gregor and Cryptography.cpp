#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int p; cin >> p;
		cout << 2 << ' ' << p - 1 << '\n';
	}
	cin.ignore(2); return 0;
}