#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main() {
	int n, k; cin >> n >> k; 
	vector<ld> v(k); ld sum = 0.0, res = 0.0;
	for (int i = 0; i < k; i++) {
		v[i] = pow((i + 1.0) / (k + 0.0), n + 0.0);
		v[i] -= sum; sum += v[i];
	}
	for (int i = 0; i < k; i++) { res += (i + 1) * v[i]; }
	cout << fixed << setprecision(6) << res << '\n';
}