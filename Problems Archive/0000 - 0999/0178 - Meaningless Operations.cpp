#include <iostream>
using namespace std;

int logb2(int n) {
	int res = 0;
	while (n != 1) { n /= 2; res++; }
	return res;
}

int find_gcd(int &n) {
	int l1 = logb2(n), l2 = logb2(n + 1);
	if (l1 == l2) {	return (1 << (l1 + 1)) - 1; }
	if (l1 % 2) { return n / 3; }
	int m = (int)floor(sqrt(n + 0.0));
	for (int i = 3; i <= m; i++) {
		if (n % i == 0) { return n / i; }
	}
	return 1;
}

int main() {
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int a; cin >> a;
		cout << find_gcd(a) << endl;
	}
	cin.ignore(2); return 0;
}