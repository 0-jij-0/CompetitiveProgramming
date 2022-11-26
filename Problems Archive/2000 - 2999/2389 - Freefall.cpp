#include <bits/stdc++.h>
using namespace std;
typedef double ld;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ld A, B; cin >> A >> B;
	ld X = pow(A / (2 * B), 2.0 / 3.0) - 1;
	ld x1 = floor(X), x2 = ceil(X);
	ld res1 = B * x1 + A / (pow(1 + x1, 0.5));
	ld res2 = B * x2 + A / (pow(1 + x2, 0.5));
	cout << fixed << setprecision(6) << min(res1, res2) << '\n';
}