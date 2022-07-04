#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
typedef long long ll;

vector<ll> v, p; map<int, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; ll x; cin >> n >> q >> x;
	v.resize(n); p.resize(n << 1);
	for (auto& x : v) { cin >> x; }
	v.insert(v.end(), v.begin(), v.end());
	partial_sum(v.begin(), v.end(), p.begin());

	vector<ll> res; int cur = 0; ll X = x % p[n - 1];
	int cycleLen = 0, cycleStart = 0;

	if (x && !X) {
		res.push_back((x / p[n - 1]) * n);
		cycleStart = 0; cycleLen = 1;
	}
	else {
		for (int i = 0; i < n; i++) {
			m[cur] = i;
			auto it = lower_bound(p.begin(), p.end(), X + (cur ? p[cur - 1] : 0));
			res.push_back(it - p.begin() - cur + 1);
			res.back() += (x / p[n - 1]) * n;
			cur = (it - p.begin() + 1) % n;

			if (m.count(cur)) {
				cycleStart = m[cur];
				cycleLen = i + 1 - m[cur];
				break;
			}

		}
	}

	while (q--) {
		ll k; cin >> k; k--;
		if (k < res.size()) { cout << res[k] << '\n'; continue; }
		cout << res[cycleStart + ((k - cycleStart) % cycleLen)] << '\n';
	}
}