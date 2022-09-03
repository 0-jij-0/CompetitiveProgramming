#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v, pref;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; pref.resize(n);
	v.resize(n); for (auto& x : v) cin >> x;
	partial_sum(v.begin(), v.end(), pref.begin());
	for (int i = 0; i < n; i++) v[i] *= (i + 1);
	partial_sum(v.begin(), v.end(), v.begin());

	ll res = v[m - 1]; for (int i = m; i < n; i++) 
		res = max(res, v[i] - v[i - m] - (i - m + 1) * (pref[i] - pref[i - m]));

	cout << res << '\n';
}