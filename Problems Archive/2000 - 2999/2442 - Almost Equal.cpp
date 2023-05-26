#include <bits/stdc++.h>
using namespace std;

vector<string> v;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto& x : v) cin >> x;
	sort(v.begin(), v.end());

	do {
		bool can = true;
		for (int i = 1, dif = 0; i < n; i++, dif = 0) {
			for (int j = 0; j < m; j++)
				dif += (v[i][j] != v[i - 1][j]);
			if (dif != 1) { can = false; break; }
		}
		if (can) { cout << "Yes\n"; return 0; }
	} while (next_permutation(v.begin(), v.end()));

	cout << "No\n";
}