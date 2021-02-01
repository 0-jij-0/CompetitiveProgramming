#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;
typedef double ld;

vector<ld> v, d; vector<int> tr;

int main() {
	int n, m, k; cin >> n >> m >> k; bool ok = true;
	v.resize(n + m + 1, 0.0); tr.resize(n + m + 1, 0); d.resize(n + m + 1, 0.0);
	for (int i = 0; i < k; i++) { int x; cin >> x; tr[x] = 1; }
	vector<int> c(n + m + 1); partial_sum(tr.begin(), tr.end(), c.begin());
	for (int i = m; i < n; i++) if (c[i] - c[i - m] == m) { ok = false; break; }
	if (!ok) { cout << -1 << '\n'; return 0; }

	ld dW = 0.0, rW = 0.0;
	for (int i = n - 1; i >= 0; i--) {
		if (tr[i] == 1) { d[i] = 1.0; v[i] = 0.0; }
		else { d[i] = dW / m; v[i] = 1 + (rW / m); }
		dW += d[i] - d[i + m]; rW += v[i] - v[i + m];
	}

	cout << fixed << setprecision(5) << v[0] / (1 - d[0]) << '\n';
	cin.ignore(2); return 0;
}