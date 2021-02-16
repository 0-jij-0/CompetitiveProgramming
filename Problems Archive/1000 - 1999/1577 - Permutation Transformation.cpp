#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v, res;

void dfs(int i, int j, int d) {
	if (i > j) { return; }
	auto it = max_element(v.begin() + i, v.begin() + j + 1);
	int idx = it - v.begin(); res[idx] = d;
	dfs(i, idx - 1, d + 1); dfs(idx + 1, j, d + 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); res.resize(n);
		for (auto& x : v) { cin >> x; }
		dfs(0, n - 1, 0);
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}