#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, a;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ifstream ifs("piles.in");

	int t; ifs >> t; while (t--) {
		int n; ifs >> n; v.resize(n); a.resize(n);
		for (auto &x : v) { ifs >> x; }
		for (auto &x : a) { ifs >> x; }

		bool ok = true; int prev = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] <= prev) { ok = false; break; }
			prev = max(prev + 1, v[i] - a[i]);
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	ifs.close(); return 0;
}