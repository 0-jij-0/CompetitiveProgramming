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

bool isPrime(int n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	if (n % 6 != 5 && n % 6 != 1) { return false; }

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	while (n != 0) {
		if (n == 1) { cout << 0 << endl; cin >> n; continue; }
		cout << (isPrime(n) ? n - 1 : euler_phi(n)) << endl; 
		cin >> n;
	}
	cin.ignore(2); return 0;
}