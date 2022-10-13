#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int thickness(int s) {
	int n = (int)v.size(), cur = 0, res = 0;
	for (int i = 0, j = 0; i < n;) {
		while (j < n && cur < s) { cur += v[j++]; }
		if (cur > s) { return 1 << 30; }
		cur = 0; res = max(res, j - i); i = j;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); int sum = 0;
		for (auto& x : v) { cin >> x; sum += x; }

		int res = n;
		for (int i = 1; i * i <= sum; i++) {
			if (sum % i) { continue; }
			res = min({ res, thickness(i), thickness(sum / i) });
		}

		cout << res << '\n';
	}
}