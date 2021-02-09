#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("diff.in", "r", stdin);

	vector<ll> fib;
	ll a = 1, b = 1;
	fib.push_back(0); fib.push_back(1);
	while (b < 2e9) {
		ll c = a + b;
		fib.push_back(c);
		a = b; b = c;
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<ll> a(n); for (auto& x : a) { cin >> x; }

		int ans = 1;
		map<ll, int> m; m[a[n - 1]] = 1;
		for (int i = n - 2; i >= 0; i--) {
			int curAns = 1;
			for (auto& f : fib) {
				ll ss = f + a[i];
				if (m.count(ss)) { curAns = max(curAns, m[ss] + 1); }
				ss = a[i] - f;
				if (m.count(ss)) { curAns = max(curAns, m[ss] + 1); }
			}
			m[a[i]] = curAns;
			ans = max(ans, curAns);
		}

		cout << ans << '\n';
	}
}