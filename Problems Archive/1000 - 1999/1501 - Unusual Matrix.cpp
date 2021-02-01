#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

bool check(vector<vector<int>> a) {
	int n = a.size();
	for (int j = 0; j < n; j++) if (v[0][j] == 1)
		for (int i = 0; i < n; i++) v[i][j] ^= 1;

	for (int i = 0; i < n; i++) {
		int a = count(v[i].begin(), v[i].end(), 0);
		if (a != 0 && a != n) { return false; }
	}
	return true;
}

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; v.clear(); v.resize(n, vector<int>(n));
		for (auto& x : v) for (auto& y : x) { char c; cin >> c; y = (c == '1'); }
		for (auto& x : v) for (auto& y : x) { char a; cin >> a; y ^= (a == '1'); }

		if (check(v)) { cout << "YES" << '\n'; continue; }
		for (auto& x : v[0]) x ^= 1;
		cout << (check(v) ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}