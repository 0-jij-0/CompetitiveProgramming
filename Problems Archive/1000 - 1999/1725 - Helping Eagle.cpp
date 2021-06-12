#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;

int main() {
	freopen("help.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); 
		ll sum = 0; int max1 = 0, max2 = 0;
		for (auto& x : v) { 
			cin >> x; sum += x;
			if (x >= max1) { max2 = max1; max1 = x; }
			else if (x > max2) { max2 = x; }
		}

		ll res = sum - max1 - max2, pref = 0, suf = sum - v[0] - v[1];
		for (int i = 1; i < n; i++) {
			res = min(res, max(pref, suf));
			if (i + 1 != n) { pref += v[i - 1]; suf -= v[i + 1]; }
		}

		cout << res << '\n';
	}
	cin.ignore(2); return 0;
}