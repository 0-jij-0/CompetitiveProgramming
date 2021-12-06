#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;
typedef long long ll;

ll findPerfArrays(vector<ll>& a) {
	partial_sum(a.begin(), a.end(), a.begin());
	int n = (int)a.size(); ll res = 0;
	set<ll> vis; vis.insert(0);

	int i = 0, j = 1; while (j < n) {
		if (!vis.count(a[j])) { res += j - i; vis.insert(a[j++]); }
		else  while (vis.count(a[j])) {	vis.erase(a[i++]); }
	}
	return res;
}

vector<int> v;

int main() {
	freopen("perfect.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		ll ans = 0; vector<ll> cur(1, 0);
		for (int i = 0; i < n; i++) {
			if (v[i] != 0) { cur.push_back(v[i]); continue; }
			ans += findPerfArrays(cur); cur = vector<ll>(1, 0);
		}
		cout << ans + findPerfArrays(cur) << '\n';
	}

	cin.ignore(2); return 0;
}