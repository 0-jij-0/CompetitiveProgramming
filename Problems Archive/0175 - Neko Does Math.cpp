#include <iostream>
using namespace std;

int find_k(long long a, long long b) {
	long long d = b - a;
	int up = (int)floor(sqrt(d + 0.0));
	int m, k; long long l;
	long long min_lcm = a * b; int min_k = 0;
	for (int i = up; i > 0; i--) {
		if (d % i) { continue; }
		m = a % i; k = i - m; k %= i;
		l = (a + k) * (b + k) / i;
		if (l < min_lcm) { min_lcm = l; min_k = k; }
		int j = (int) d / i;
		m = a % j; k = j - m; k %= j;
		l = (a + k) * (b + k) / j;
		if (l < min_lcm) { min_lcm = l; min_k = k; }
	}
	return min_k;
}

int main() {
	long long a, b; cin >> a >> b;
	if (a > b) { swap(a, b); }
	int k = find_k(a, b);
	cout << k << endl;
	cin.ignore(2); return 0;
}