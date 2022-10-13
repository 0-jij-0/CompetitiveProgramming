#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		if (n == 1 || n == 3) { cout << "-1\n"; continue; }
		if (n == 2) { cout << "2 1\n"; continue; }

		vector<int> res(n);
		iota(res.begin(), res.end(), 1);
		rotate(res.begin(), res.begin() + 2, res.end());
		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
}