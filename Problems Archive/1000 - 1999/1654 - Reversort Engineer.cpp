#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, c; cin >> n >> c;
		if (c < (n - 1)) { cout << "Case #" << t << ": IMPOSSIBLE\n"; continue; }
		if ((c - (n - 1)) > (n * (n - 1)) / 2) { cout << "Case #" << t << ": IMPOSSIBLE\n"; continue; }

		vector<int> rev(n, 0); for (int i = 0; i < n - 1; i++) {
			if (c - ((n - 2) - i) >= n - i) { rev[i] = 1; c -= n - i; }
			else { c--; }
		}

		vector<int> res(n); iota(res.begin(), res.end(), 1);
		for (int i = n - 2; i >= 0; i--) if (rev[i]) reverse(res.begin() + i, res.end());
		cout << "Case #" << t << ": "; for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}