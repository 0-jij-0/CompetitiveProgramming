#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> r;

void fill_r() {
	r.resize(27);
	long long range = 1; r[0] = 1;
	for (int i = 1; i < 27; i++) {
		if (i % 2) { r[i] = 5 * r[i - 1]; }
		else { r[i] = r[i - 1] + 2 * range; }
		range *= 5;
	}
}

bool check(long long n) {
	long long res = 0; long long m = 5;
	while (m <= n) { res += n / m; m *= 5; }
	return (res % 2) == 0;
}

int main() {
	fill_r(); 
	long long n; cin >> n;
	while (n != -1) {
		bool b = check(n);
		long long mask = 1; int i = 0;
		while (5 * mask < n) { i++; mask *= 5; }
		long long res = 0; bool rev = false;
		while (i >= 0) {
			if (n < mask) { mask /= 5; i--; continue; }
			long long x = n / mask;
			long long a = (rev) ? mask - r[i] : r[i];
			if (i % 2 == 0) { res += a * x; }
			else { 
				res += mask * (x / 2) + a * (x % 2);
				if (x % 2) { rev = !rev; }
			}
			n -= x * mask; mask /= 5; i--;
		}
		cout << res + b << endl; cin >> n;
	}
	cin.ignore(2); return 0;
}