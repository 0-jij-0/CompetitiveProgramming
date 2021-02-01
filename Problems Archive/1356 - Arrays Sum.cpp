#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k; v.resize(n);
		for (auto &x : v) { cin >> x; }
		v.erase(unique(v.begin(), v.end()), v.end());
		if (k == 1) { cout << (v.size() == 1 ? 1 : -1) << '\n'; continue; }
		int s = (int)v.size(); if (s <= k) { cout << 1 << '\n'; continue; }
		int res = 1 + (s - 2) / (k - 1); cout << res << '\n';
	}
	cin.ignore(2); return 0;
}