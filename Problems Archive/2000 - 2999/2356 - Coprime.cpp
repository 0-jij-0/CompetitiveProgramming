#include <bits/stdc++.h>
using namespace std;

vector<int> v, idx;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		idx.clear(); idx.resize(1001, 0);
		for (int i = 0; i < n; i++) {
			cin >> v[i]; idx[v[i]] = i + 1;
		}

		int res = -1;
		if (count(v.begin(), v.end(), 1)) {
			auto it = find(v.rbegin(), v.rend(), 1);
			res = (n - (it - v.rbegin())) << 1;
		}

		for (int i = 1; i <= 1000; i++)
			for (int j = i + 1; j <= 1000; j++)
				if (gcd(i, j) == 1 && idx[i] && idx[j])
					res = max(res, idx[i] + idx[j]);

		cout << res << '\n';
	}
}