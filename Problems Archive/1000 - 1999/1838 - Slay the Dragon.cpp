#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	int n; cin >> n; v.resize(n); ll sum = 0;
	for (auto& x : v) { cin >> x; sum += x; }
	sort(v.begin(), v.end());

	int m; cin >> m; while (m--) {
		ll x, y; cin >> x >> y;
		auto it = lower_bound(v.begin(), v.end(), x);
		if (it == v.end()) { it--; }
		ll cur1 = max(0ll, (x - *it)) + max(0ll, y - (sum - *it));
		if (it != v.begin()) { it--; }
		ll cur2 = max(0ll, (x - *it)) + max(0ll, y - (sum - *it));
		cout << min(cur1, cur2) << '\n';
	}

	cin.ignore(2); return 0;
}