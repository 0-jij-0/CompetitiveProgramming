#include <iostream>
using namespace std;

const int mod = 1000000007;

int logb2(long long n) {
	int res = 0;
	while (n != 1) { res++; n /= 2; }
	return res;
}

long long find_sum(long long idx) {
	if (idx == 0) { return 0; }
	long long e = 0, o = 0;
	int n = logb2(idx); bool odd = true;
	for (int i = 0; i < n; i++) {
		if (odd) { o += 1ll << i; }
		else { e += 1ll << i; }
		odd = !odd;
	}
	if (odd) { o += idx - (1ll << n) + 1; }
	else { e += idx - (1ll << n) + 1; }
	long long total_sum = 0;
	total_sum += ((e % mod) * ((e + 1) % mod)) % mod;
	total_sum += ((o % mod) * (o % mod)) % mod;
	return total_sum % mod;
}

int main() {
	long long l, r; cin >> l >> r;
	long long total_sum = ((find_sum(r) - find_sum(l - 1)) + mod) % mod;
	cout << total_sum << endl;
	cin.ignore(2); return 0;
}