#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v, pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, x; cin >> n >> x;
		v.resize(n); pref.resize(n);
		for (auto& x : v) { cin >> x; }
		sort(v.begin(), v.end());
		partial_sum(v.begin(), v.end(), pref.begin());

		int N = 0; while (N < n && pref[N] <= x) { N++; }
		
		ll res = 0, d = 0; int i = N - 1;
		
		while (i >= 0) {
			if (pref[i] + d * (i + 1) > x) { i--; continue; }
			ll diff = x - (pref[i] + d * (i + 1));
			ll inc = diff / (i + 1); d += inc + 1;
			res += (inc + 1) * (i + 1);
		}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}