#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
typedef double ld;

const ld EPS = 0.0001;

ld area(ld a, ld b, ld c) {
	ld p = (a + b + c) / 2.0;
	return p * (p - a) * (p - b) * (p - c);
}

ld solve(int a, int b, int c, int k) {
	ld L = max(a, c - b), R = min(a + k, b + c);
	for (int i = 0; i < 20; i++) {
		ld mid = (L + R) / 2.0;
		ld M = area(mid, b, c);
		ld left = area(mid - EPS, b, c);
		ld right = area(mid + EPS, b, c);

		ld cur = max({ M, left, right });
		if (cur == M) { return sqrt(area(mid, b, c)); }
		if (cur == left) { R = mid; continue; }
		if (cur == right) { L = mid; continue; }
	}
	return sqrt(area((L + R) / 2.0, b, c));
}

int main() {
	freopen("sticks.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int a, b, c, k; cin >> a >> b >> c >> k;

		if (a > b) { swap(a, b); }
		if (b > c) { swap(b, c); }
		if (a > b) { swap(a, b); }

		ld A = solve(a, b, c, k), B = solve(b, a, c, k), C = solve(c, a, b, k);
		cout << fixed << setprecision(10) << max({ A, B, C }) << '\n';
	}
	cin.ignore(2); return 0;
}