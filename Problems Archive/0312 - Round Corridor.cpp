#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (a < b) { swap(a, b); }
	return b ? gcd(b, a%b) : a;
}

int main() {
	long long n, m, q; cin >> n >> m >> q;
	long long g = gcd(n, m); n /= g; m /= g;
	while (q--) {
		long long sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sy--; ey--;
		if (sx == 1) { sy /= n; }
		else { sy /= m; }
		if (ex == 1) { ey /= n; }
		else { ey /= m; }
		if (sy == ey) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}