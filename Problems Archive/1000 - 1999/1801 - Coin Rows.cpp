#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v[2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v[0].resize(n); v[1].resize(n);
		for (auto& x : v[0]) cin >> x;
		for (auto& x : v[1]) cin >> x;
		partial_sum(v[0].rbegin(), v[0].rend(), v[0].rbegin());
		partial_sum(v[1].begin(), v[1].end(), v[1].begin());
		if (n == 1) { cout << 0 << '\n'; continue; }

		ll res = min(v[0][1], v[1][n - 2]);
		for (int i = 1; i < n - 1; i++)
			res = min(res, max(v[0][i + 1], v[1][i - 1]));
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}