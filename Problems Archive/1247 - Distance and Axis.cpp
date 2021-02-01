#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		if (n < k) { cout << k - n << '\n'; continue; }
		cout << (n - k) % 2 << endl;
	}
	cin.ignore(2); return 0;
}