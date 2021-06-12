#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	freopen("bad-memes.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) { cin >> x; }
		partial_sum(v.begin(), v.end(), v.begin());
		v.insert(v.begin(), 0);

		ll res = -(1ll << 60); for (int i = 1; i <= n; i++) {
			int j = i; ll ans = 1ll << 60; 
			for (; j <= n; j += i) ans = min(ans, v[j] - v[j - i]);
			if (j - i != n) { ans = min(ans, v[n] - v[j - i]); }
			res = max(res, ans);
		}
		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}