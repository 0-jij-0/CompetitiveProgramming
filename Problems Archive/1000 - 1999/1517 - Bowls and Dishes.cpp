#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

vector<array<int, 2>> c;
vector<array<int, 2>> p;

int main() {
	int n, m; cin >> n >> m; c.resize(m);
	for (auto& x : c) cin >> x[0] >> x[1];
	int k; cin >> k; p.resize(k);
	for (auto& x : p) cin >> x[0] >> x[1];

	int res = 0;
	for (int i = 0; i < (1 << k); i++) {
		vector<bool> d(n, 0); int cur = 0;
		for (int j = 0; j < k; j++)
			d[p[j][(i & (1 << j)) != 0] - 1] = true;
		for (auto& x : c) cur += (d[x[0] - 1] && d[x[1] - 1]);
		res = max(res, cur);
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}