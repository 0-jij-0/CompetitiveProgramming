#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, k;

bool check(ll x) {
	ll less = 0; for (int i = 1; i <= n; i++)
		less += min((x - 1) / i, n);

	return less < k;
}

ll findKth() {
	ll L = 1, R = n * n;
	while (L != R) {
		ll M = (L + R + 1) >> 1;
		check(M) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	cin >> n >> k;
	cout << findKth() << '\n';
}