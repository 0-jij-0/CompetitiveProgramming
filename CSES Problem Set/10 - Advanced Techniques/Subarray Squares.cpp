#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

ll dp[2][3000];
vector<ll> v;

ll cost(int L, int R) {
	ll res = v[R] - (L ? v[L - 1] : 0);
	return res * res;
}

void divideAndConquerStep(ll prev[], ll cur[], int L, int R, int optL, int optR) {
	if (L > R) return;
	
	int M = (L + R) >> 1;
	pair<ll, int> opt = { 1ll << 62, -1 };
	for (int i = optL; i <= min(M, optR); i++)
		opt = min(opt, { (i ? prev[i - 1] : 0) + cost(i, M), i });

	cur[M] = opt.first;
	divideAndConquerStep(prev, cur, L, M - 1, optL, opt.second);
	divideAndConquerStep(prev, cur, M + 1, R, opt.second, optR);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k; v.resize(n);
	for (auto& x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());

	for (int i = 0; i < n; i++) dp[1][i] = cost(0, i);

	for (int i = 2; i <= k; i++)
		divideAndConquerStep(dp[(i & 1) ^ 1], dp[i & 1], 0, n - 1, 0, n - 1);

	cout << dp[k & 1][n - 1] << '\n';
}