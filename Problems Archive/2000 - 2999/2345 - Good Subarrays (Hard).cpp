#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<int> A;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; A.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i]; A[i] -= i + 1;
	}

	vector<int> stop1(n), stop2(n);

	ll ans = 0;
	for (int i = 0, j1 = 0, j2 = 0; i < n; i++) {
		while (j1 < n && A[j1] + i >= 0) { j1++; }
		stop1[i] = j1; if (j1 == n) { stop2[i] = n; }
		else {
			j2 = max(j2, j1 + 1);
			while (j2 < n && A[j2] + i >= 0) { j2++; }
			stop2[i] = j2;
		}
		ans += j1 - i;
	}

	vector<ll> res1(n), res2(n);
	for (int i = 0; i < n; i++) {
		res1[i] = stop1[i] - i;
		res2[i] = stop2[i] - i;
	}

	partial_sum(res1.begin(), res1.end(), res1.begin());
	partial_sum(res2.begin(), res2.end(), res2.begin());

	int q; cin >> q; while (q--) {
		int p, x; cin >> p >> x; x -= p--;
		if (x == A[p]) { cout << ans << '\n'; continue; }
		if (x > A[p]) {
			int mi = max(0, -x);
			mi = max(mi, lower_bound(stop1.begin(), stop1.end(), p) - stop1.begin());
			int j = upper_bound(stop1.begin() + mi, stop1.end(), p) - stop1.begin();
			if (j == mi) { cout << ans << '\n'; continue; }
			ll dec = res1[j - 1] - (mi ? res1[mi - 1] : 0);
			ll inc = res2[j - 1] - (mi ? res2[mi - 1] : 0);
			cout << ans + inc - dec << '\n';
		}
		else {
			int mi = max(0, -x); if (mi == 0) { cout << ans << '\n'; continue; }
			int j = lower_bound(stop1.begin(), stop1.begin() + mi, p) - stop1.begin();
			if (j == mi) { cout << ans << '\n'; continue; }
			ll num = (mi - j);
			ll dec = res1[mi - 1] - (j ? res1[j - 1] : 0);
			ll inc = 1ll * (p - j) * num - num * (num - 1) / 2;
			cout << ans + inc - dec << '\n';
		}
	}
	
}