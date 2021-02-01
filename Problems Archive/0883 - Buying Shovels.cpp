#include <iostream>
using namespace std;

int query(int n, int k) {
	if (n <= k) { return 1; }
	int res = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i) { continue; }
		if (n / i < res && i <= k) { res = n / i; }
		if (i < res && n / i <= k) { res = i; }
	}
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		cout << query(n, k) << endl;
	}
	cin.ignore(2); return 0;
}