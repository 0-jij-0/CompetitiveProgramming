#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
typedef double ld;

vector<int> v; int n, k;

bool check(ld M) {
	int res = 0;
	for (auto& x : v) res += (int)floor(x / M);
	return res >= k;
}

ld maxRopeLength() {
	ld L = 0.0, R = 1e7 + 1;
	for (int i = 0; i < 50; i++) {
		ld M = (L + R) / 2.0;
		check(M) ? L = M : R = M;
	}
	return L;
}

int main() {
	cin >> n >> k; v.resize(n);
	for (auto& x : v) cin >> x;
	cout << fixed << setprecision(6) << maxRopeLength() << '\n';
}