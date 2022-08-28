#include <iostream>
#include <iomanip>
using namespace std;
typedef double ld;

ld E[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; E[1] = 3.5;
	for (int i = 2; i <= n; i++) {
		ld e = 0.0, p = 0.0;
		for (int j = 1; j <= 6; j++)
			j < E[i - 1] ? p += 1.0 : e += j;
		E[i] = (e / 6.0) + (p / 6.0) * E[i - 1];
	}

	cout << fixed << setprecision(7) << E[n] << '\n';
}
