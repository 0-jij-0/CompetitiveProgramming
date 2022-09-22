#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2e9 + 1;

vector<pair<ll, ll>> v; int n; ll k;

bool check(ll M) {
	ll res = 0; for (auto& [L, R] : v)
		res += max(0ll, 1 + min(R, M - 1) - L);

	return res <= k;
}

int findKth() {
	ll L = -INF, R = INF;
	while (L != R) {
		int M = (L + R + 1) >> 1;
		check(M) ? L = M : R = M - 1;
	}
	return L;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k; v.resize(n);
	for (auto& [L, R] : v) cin >> L >> R;
	cout << findKth() << '\n';
}