#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

ll eulerPhi(ll n) {
	ll res = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) { n /= i; }
			res -= res / i;
		}
	if (n > 1) { res -= res / n; }
	return res;
}

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
	freopen("ages.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int p; cin >> p; p--; ll res = 0;
		for (int i = 1; i * i <= p; i++) {
			if (p % i) { continue; }
			res += eulerPhi(i) * i;
			if (p / i != i) res += eulerPhi(p / i)*(p / i);
		}
		ll g = gcd(res, p);
		cout << res / g << '/' << p / g << '\n';
	}

	cin.ignore(2); return 0;
}