#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, l, r, k; cin >> n >> l >> r >> k;
		v.resize(n); for (auto& x : v) cin >> x;
		sort(v.begin(), v.end());

		int res = 0; for (auto& x : v) {
			if (x < l) { continue; }
			if (x > r || x > k) { break; }
			k -= x; res++;
		}
		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}