#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	ll m = 0, e = 0, c = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		m += abs(x); e += x * x;
		c = max(c, abs(x));
	}
	cout << fixed << setprecision(10);
	cout << m << '\n' << sqrt(e) << '\n' << c << '\n';
}