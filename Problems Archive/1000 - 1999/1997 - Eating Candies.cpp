#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> v, suf;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); suf.resize(n);
		for (auto& x : v) { cin >> x; }

		partial_sum(v.rbegin(), v.rend(), suf.rbegin());
		int pref = 0, res = 0;
		for (int i = 0; i < n; i++) {
			auto it = lower_bound(suf.rbegin(), suf.rbegin() + (n - 1 - i), pref += v[i]);
			if (it != (suf.rbegin() + (n - 1 - i)) && *it == pref) { 
				res = max(res, i + (it - suf.rbegin()) + 2);
			}
		}

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}