#include <iostream>
using namespace std;

int logb2(long long n) {
	int res = 0;
	while (n != 1) { res++; n /= 2; }
	return res;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		long long n; cin >> n; int x = logb2(n);
		long long res = n * (n + 1) / 2;
		res -= 2 * ((1ll << (x + 1)) - 1);
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}