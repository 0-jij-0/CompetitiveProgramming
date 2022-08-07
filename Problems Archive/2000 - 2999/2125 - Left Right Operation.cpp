#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v, pref, suff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; ll L, R; cin >> n >> L >> R;
	v.resize(n); pref.resize(n); suff.resize(n);
	for (auto& x : v) { cin >> x; }

	partial_sum(v.begin(), v.end(), pref.begin());
	partial_sum(v.rbegin(), v.rend(), suff.rbegin());
	for (int i = 0; i < n; i++)
		suff[n - 1 - i] -= (i + 1) * R;

	vector<int> suffMax(n); suffMax[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--)
		suffMax[i] = (suff[i] > suff[suffMax[i + 1]]) ? i : suffMax[i + 1];

	ll res = accumulate(v.begin(), v.end(), 0ll);
	for (int i = 0; i < n - 1; i++) {
		int idx = suffMax[i + 1];
		ll left = min(pref[i], (i + 1) * L);
		ll mid = pref[idx - 1] - pref[i];
		ll right = min(pref.back() - pref[idx - 1], R * (n - idx));
		res = min(res, left + mid + right);
	}

	cout << min({res, L * n, R * n}) << '\n';
}