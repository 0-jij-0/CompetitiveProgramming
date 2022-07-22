#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; v.resize(n);
	for (auto& x : v) cin >> x;

	vector<ll> pref(n), suff(n);
	pref[0] = 0;
	for (int i = 1; i < n; i++)
		pref[i] = max(0ll, v[i - 1] - v[i]);

	suff[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--)
		suff[i] = max(0ll, v[i + 1] - v[i]);

	partial_sum(pref.begin(), pref.end(), pref.begin());
	partial_sum(suff.rbegin(), suff.rend(), suff.rbegin());

	while (m--) {
		int l, r; cin >> l >> r; l--; r--;
		if (l < r) { cout << pref[r] - pref[l] << '\n'; }
		else { cout << suff[r] - suff[l] << '\n'; }
	}
}