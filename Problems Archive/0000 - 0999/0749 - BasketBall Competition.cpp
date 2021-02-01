#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

vector<vector<pair<int, int>>> range;
vector<ll> v;

ll dp[16400][15];
ll cost(int i, int j) {
	if (v[i] > v[j]) { return 0; }
	ll d = v[j] - v[i];
	return d * d;
}

ll minCost(int i, int r) {
	if (r == 0) { return 0; }
	if (dp[i][r] != -1) { return dp[i][r]; }

	pair<int, int> rng = range[i][r];
	int mid = (rng.first + rng.second) >> 1;
	ll a = minCost(i, r - 1);
	ll res = 1ll << 62;
	if (i > mid) {
		for (int j = rng.first; j <= mid; j++) {
			ll b = minCost(j, r - 1);
			res = min(res, a + cost(i, j) + b);
		}
	}
	else {
		for (int j = mid + 1; j <= rng.second; j++) {
			ll b = minCost(j, r - 1);
			res = min(res, a + cost(i, j) + b);
		}
	}
	return dp[i][r] = res;
}

int main() {
	int r; cin >> r; int n = 1 << r;
	range.resize(n); v.resize(n);
	memset(dp, -1, sizeof(dp));
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i <= r; i++) {
		int rng = 1 << i;
		for (int j = 0; j < n; j += rng) {
			int l = j, r = j + rng - 1;
			for (int k = 0; k < rng; k++) {
				range[j + k].push_back({ l, r });
			}
		}
	}
	cout << minCost(0, r) << endl;
	cin.ignore(2); return 0;
}