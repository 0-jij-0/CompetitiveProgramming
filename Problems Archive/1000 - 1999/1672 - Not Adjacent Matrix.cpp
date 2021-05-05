#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n;
		if (n == 1) { cout << 1 << '\n'; continue; }
		if (n == 2) { cout << -1 << '\n'; continue; }
		v.clear(); v.resize(n, vector<int>(n));
		int cur = 1;
		for (int i = 0; i < n * n; i++) {
			int r = i / n, c = i % n;
			v[r][c] = cur; cur += 2;
			if (cur > n * n) { cur = 2; }
		}
		for (auto& x : v) { for (auto& y : x) cout << y << ' '; cout << '\n'; }
	}
	cin.ignore(2); return 0;
}