#include <iostream>
using namespace std;

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		long long n; cin >> n;
		int count = 0;
		while (n % 5 == 0) {
			n /= 5; n *= 4; count++;
		}
		while (n % 3 == 0) {
			n /= 3; n *= 2; count++;
		}
		while (n % 2 == 0) {
			n /= 2; count++;
		}
		if (n == 1) { cout << count << endl; }
		else { cout << -1 << endl; }
	}
	cin.ignore(2); return 0;
}