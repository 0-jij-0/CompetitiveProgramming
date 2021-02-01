#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, res;

int main() {
	int n, m; cin >> n >> m; v.resize(m); long long s = 0;
	for (auto &x : v) { cin >> x; s += x; }
	if (s < n) { cout << -1 << endl; return 0; }

	bool b = true; 
	for (int i = 0; i < m; i++) {
		if (i + v[i] > n) { b = false; break; }
	}
	if (!b) { cout << -1 << endl; return 0; }

	res.resize(m); int target = n;
	for (int i = m - 1; i >= 0; i--) {
		res[i] = max(i, target - v[i]);
		target = res[i];
	}
	for (auto &x : res) { cout << x + 1 << ' '; }
	cout << endl; cin.ignore(2); return 0;
}