#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int l, r, k; cin >> l >> r >> k;
		if (k == 0 && l == r && l > 1) { cout << "YES\n"; continue; }
		if (k == 0) { cout << "NO\n"; continue; }

		int e = r / 2 - (l - 1) / 2, o = r - l + 1 - e;
		cout << (o > k ? "NO" : "YES") << '\n';
	}
	cin.ignore(2); return 0;
}