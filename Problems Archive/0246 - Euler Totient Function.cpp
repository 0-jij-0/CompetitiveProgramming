#include <iostream>
#include <cmath>
using namespace std;

int euler_phi(int n) {
	int res = n; int m = (int)floor(sqrt(n));
	for (int i = 2; i <= m; i++)
		if (n % i == 0) {
			while (n % i == 0) { n /= i; }
			res -= res / i;
		}
	if (n > 1) { res -= res / n; }
	return res;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << euler_phi(n) << endl;
	}
	return 0;
}