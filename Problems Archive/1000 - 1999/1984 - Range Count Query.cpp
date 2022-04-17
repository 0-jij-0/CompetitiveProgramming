#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		v[x].push_back(i);
	}

	int q; cin >> q; while (q--) {
		int l, r, x; cin >> l >> r >> x;
		auto L = lower_bound(v[x].begin(), v[x].end(), l);
		auto R = upper_bound(v[x].begin(), v[x].end(), r);
		cout << R - L << '\n';
	}

	cin.ignore(2); return 0;
}