#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		long long n, k; cin >> n >> k;
		long long count = 0;
		while (n != 0) {
			long long a = n % k;
			if (a != 0) { n -= a; count += a; }
			else { n /= k; count++; }
		}
		cout << count << endl;
	}
	cin.ignore(2); return 0;
}