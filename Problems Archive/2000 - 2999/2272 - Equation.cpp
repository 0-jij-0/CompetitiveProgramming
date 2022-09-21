#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef double ld;

ld solveEquation(ld C) {
	ld L = 0, R = 1e5;
	for (int i = 0; i < 50; i++) {
		ld M = (L + R) / 2.0;
		(M * M + sqrt(M)) < C ? L = M : R = M;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ld C; cin >> C;
	cout << fixed << setprecision(6) << solveEquation(C) << '\n';
}