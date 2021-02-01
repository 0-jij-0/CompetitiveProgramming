#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> c, f, h, freq, fav;
ll dp[501][5001]; int n, k;

ll findMax(int x, int y) {
	if (x == 0 || y == 0) { return 0; }
	if (dp[x][y] != -1) { return dp[x][y]; }

	ll res = 0;
	for (int i = 0; i <= min(y, k); i++)
		res = max(res, h[i] + findMax(x - 1, y - i));
	return dp[x][y] = res;
}

int main() {
	cin >> n >> k; ll res = 0;
	c.resize(n * k); f.resize(n); h.resize(k);
	freq.resize(100001, 0); fav.resize(100001, 0);
	for (auto &x : c) { cin >> x; freq[x]++; }
	for (auto &x : f) { cin >> x; fav[x]++; }
	for (auto &x : h) { cin >> x; }

	fill(dp[0], dp[0] + 501 * 5001, -1); h.insert(h.begin(), 0);
	for (int i = 1; i <= 100000; i++) { res += findMax(fav[i], freq[i]); }
	cout << res << endl; cin.ignore(2); return 0;
}