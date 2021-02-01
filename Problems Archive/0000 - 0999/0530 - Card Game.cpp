#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k1, k2; cin >> n >> k1 >> k2;
		bool b = true;
		for (int i = 0; i < k1; i++) {
			int a; cin >> a;
		}
		for (int i = 0; i < k2; i++) {
			int a; cin >> a;
			if (a == n) { b = false; }
		}
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}