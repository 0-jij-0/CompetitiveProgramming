#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

ll sqrt_bs(ll n) {
	ll L = 0, R = 1000000;
	while (L != R) {
		ll M = (L + R) >> 1;
		M * M < n ? L = M + 1 : R = M;
	}
	return L;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M; cin >> N >> M; ll n = sqrt_bs(M);
	if (n > N) { cout << -1 << '\n'; return 0; }
	
	ll res = n * n;
	for (ll i = 1; i <= n; i++) {
		ll j = (M + i - 1) / i;
		if (j <= N) res = min(res, j * i);
	}
	cout << min(res, n * n) << '\n';
}