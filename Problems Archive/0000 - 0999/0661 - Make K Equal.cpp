#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
using namespace std;
typedef long long ll;

vector<ll> v, pref, suf;
map<ll, pair<int, int>> m;

int main() {
	int n, k; cin >> n >> k; v.resize(n);
	pref.resize(n); suf.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	partial_sum(v.begin(), v.end(), pref.begin());
	partial_sum(v.rbegin(), v.rend(), suf.rbegin());
	for (int i = 0; i < n; i++) {
		if (!m.count(v[i])) { m[v[i]] = { i, i }; }
		else { m[v[i]].second++; }
	}

	ll res = 1ll << 60;
	for (auto &x : m) {
		int i = x.second.first, j = x.second.second;
		
		ll a = (i == 0) ? 0 : i * (v[i] - 1) - pref[i - 1];
		ll b = (j == n - 1) ? 0 : suf[j + 1] - (n - j - 1)*(v[j] + 1);

		if (j + 1 >= k) { res = min(res, a + max(0ll, (ll) k - (j - i + 1))); }
		else {
			ll c = suf[j + 1] - (n - 1 - j)*(v[j] + 1);
			a += i + c + (k - (j + 1)); res = min(res, a);
		}
		if (n - i >= k) { res = min(res, b + max(0ll, (ll) k - (j - i + 1))); }
		else {
			ll c = i * (v[i] - 1) - pref[i - 1];
			b += n - 1 - j + c + (k - (n - i)); res = min(res, b);
		}
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}