#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

bool isPrime(int n) {
	if (n < 2) { return false; }
	if (n < 4) { return true; }
	if (n % 6 != 1 && n % 6 != 5) { return false; }

	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0) { return false; }
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	while (n--) {
		double x, y; cin >> x >> y;
		int a = (int)floor(1000 * 1000 * x + 0.1), b = (int)floor(1000 * 1000 * y + 0.1);
		int g = gcd(a, b); a /= g; b /= g;
		if (a == b) { cout << 2 << ' ' << 2 << endl; continue; }
		cout << (isPrime(a) && isPrime(b) ? to_string(a) + " " + to_string(b) : "impossible") << endl;
	}
	cin.ignore(2); return 0;
}