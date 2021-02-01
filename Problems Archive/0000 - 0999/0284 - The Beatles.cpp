#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) { swap(a, b); }
	return b ? gcd(b, a%b) : a;
}

int main() {
	long long n, k; cin >> n >> k;
	long long a, b; cin >> a >> b;
	long long c[4];
	c[0] = (a + b) % k; c[1] = (a - b + k) % k;
	c[2] = (b - a + k) % k; c[3] = (-a - b + 2 * k) % k;
	long long mini = n * k, maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			long long l = n * k / gcd(n*k, k*i + c[j]);
			mini = min(mini, l); maxi = max(maxi, l);
		}
	}
	cout << mini << ' ' << maxi << endl;
	cin.ignore(2); return 0;
}