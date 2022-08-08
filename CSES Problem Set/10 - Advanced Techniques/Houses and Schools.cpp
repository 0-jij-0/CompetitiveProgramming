#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

ll dp[2][3000]; int n;
vector<ll> pref, pref2, suff, suff2;

ll suffCost(int L, int R) {
	if (L > R) return 0;
	ll rangeSum = L ? (R - L + 1) * pref[L - 1] : 0;
	return pref2[R] - (L ? pref2[L - 1] : 0) - rangeSum;
}

ll prefCost(int L, int R) {
	if (L > R) return 0;
	ll rangeSum = R != n - 1 ? (R - L + 1) * suff[R + 1] : 0;
	return suff2[L] - (R != n - 1 ? suff2[R + 1] : 0) - rangeSum;
}

void divideAndConquerStep(ll prev[], ll cur[], int L, int R, int optL, int optR) {
	if (L > R) return;

	int M = (L + R) >> 1;
	pair<ll, int> opt = { 1ll << 62, -1 };
	for (int i = optL; i <= min(M - 1, optR); i++) {
		int mid = (i + M) >> 1;
		ll leftCost = prefCost(i + 1, mid), rightCost = suffCost(mid + 1, M - 1);
		opt = min(opt, { prev[i] + leftCost + rightCost, i });
	}

	cur[M] = opt.first;
	divideAndConquerStep(prev, cur, L, M - 1, optL, opt.second);
	divideAndConquerStep(prev, cur, M + 1, R, opt.second, optR);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int k; cin >> n >> k;
	pref.resize(n); pref2.resize(n);
	suff.resize(n); suff2.resize(n);
	for (auto& x : pref) { cin >> x; }
	partial_sum(pref.rbegin(), pref.rend(), suff.rbegin());
	partial_sum(pref.begin(), pref.end(), pref.begin());
	partial_sum(pref.begin(), pref.end(), pref2.begin());
	partial_sum(suff.rbegin(), suff.rend(), suff2.rbegin());


	dp[1][0] = 0; for (int i = 1; i < n; i++)
		dp[1][i] = suffCost(0, i - 1);

	for (int i = 2; i <= k; i++) {
		divideAndConquerStep(dp[(i & 1) ^ 1], dp[i & 1], 0, n - 1, i - 2, n - 1);
	}

	ll res = dp[k & 1][n - 1]; for (int i = n - 1; i >= k - 1; i--)
		res = min(res, dp[k & 1][i - 1] + prefCost(i, n - 1));

	cout << res << '\n';
}