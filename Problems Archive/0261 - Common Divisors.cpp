#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> v;

long long gcd(long long a, long long b) { return b ? gcd(b, a %b) : a; }

int num_divisors(long long n) {
	int res = 2;
	long long m = (int)floor(sqrt(n + 0.0));
	for (long long i = 2ll; i <= m; i++) {
		if (n % i == 0) { res += 2; }
	}
	if (m * m == n) { res--; }
	return res;
}

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	long long g = 0;
	for (auto &x : v) {
		if (g < x) { g = gcd(x, g); }
		else { g = gcd(g, x); }
	}
	cout << num_divisors(g) << endl;
	cin.ignore(2); return 0;
}