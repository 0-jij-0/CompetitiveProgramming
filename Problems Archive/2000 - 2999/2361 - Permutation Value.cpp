#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; vector<int> res(n);
		iota(res.begin(), res.end(), 1);
		swap(res[1], res[n - 1]);
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}