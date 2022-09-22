#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef double ld;
const ld EPS = 1e-10;

vector<int> A, B; int n, k;

bool check(ld M) {
	vector<ld> v(n);
	for (int i = 0; i < n; i++)	v[i] = A[i] - M * B[i];
	nth_element(v.rbegin(), v.rend() - k, v.rend());
	return accumulate(v.begin(), v.begin() + k, 0.0) > -EPS;
}

ld maxRatio() {
	ld L = 0, R = 1e10;
	for (int i = 0; i < 100; i++) {
		ld M = (L + R) / 2.0;
		check(M) ? L = M : R = M;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k; A.resize(n); B.resize(n);
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
	cout << fixed << setprecision(6) << maxRatio() << '\n';
}