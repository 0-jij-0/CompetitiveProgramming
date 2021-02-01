#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> v;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		v.resize(n); for (auto &x : v) { cin >> x; }
		auto it = max_element(v.begin(), v.end());
		if (k >= m - 1) {
			int l = 0, r = n - m, res = 0;
			while (r != n)
				res = max(res, max(v[l++], v[r++]));
			cout << res << endl; continue;
		}
		int x = m - 1 - k;
		int l = 0, r = n - k - 1, res = 0;
		while (r != n) {
			int ll = l, rr = r - x, ans = *it;
			while (rr != r + 1)
				ans = min(max(v[ll++], v[rr++]), ans);
			res = max(ans, res); l++; r++;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}