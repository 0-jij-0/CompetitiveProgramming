#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v, pref, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; res.clear();
		v.resize(n); pref.resize(n);
		for (auto& x : v) { cin >> x; }
		partial_sum(v.begin(), v.end(), pref.begin());

		ll sum = pref.back();
		for (int i = 1; i < n; i++)
			pref[i] = max(pref[i], pref[i - 1]);

		while (m--) {
			ll x; cin >> x;
			if (sum <= 0 && pref.back() < x) { res.push_back(-1); continue; }
			if (sum <= 0) { 
				auto it = lower_bound(pref.begin(), pref.end(), x);
				res.push_back(it - pref.begin()); continue;
			}

			ll y = max(0ll, x - pref.back()), ans = n * (y / sum);
			x -= sum * (y / sum);
			while (x > pref.back()) { ans += n; x -= sum; }
			auto it = lower_bound(pref.begin(), pref.end(), x);
			res.push_back(ans + (it - pref.begin()));
		}

		for (auto& x : res) cout << x << ' '; cout << '\n';
	}
	cin.ignore(2); return 0;
}