#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> X, Y;

int main() {
	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k;
		X.resize(n); Y.resize(n);
		for (auto &x : X) { cin >> x; }
		for (auto &y : Y) { cin >> y; }
		sort(X.begin(), X.end());
		vector<int> res(n); int i = 0, j = 0;
		while (j != n) {
			if (X[j] - X[i] <= k) { j++; continue; }
			while (X[j] - X[i] > k) { res[i] = j - i; i++; }
		}
		while (i != n) { res[i] = j - i; i++; }
		vector<int> suf(n); suf.back() = res.back();
		for (i = n - 2; i >= 0; i--) suf[i] = max(res[i], suf[i + 1]);
		int ans = 0; for (int i = 0; i < n; i++) {
			int a = res[i]; auto it = upper_bound(X.begin() + i, X.end(), X[i] + k);
			int b = it == X.end() ? 0 : suf[it - X.begin()];
			ans = max(ans, a + b);
		}
		cout << ans << '\n';
	}
	cin.ignore(2); return 0;
}