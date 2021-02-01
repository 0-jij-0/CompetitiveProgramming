#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<long long, long long>> v;
long long dp[300005][3]; int n;
long long inf = 1000000ll * 1000000ll * 1000000ll + 1ll;

long long count_moves(int i, int j) {
	if (dp[i][j] != -1ll) { return dp[i][j]; }
	if (i == n) { return 0ll; }
	long long a, b, c;
	a = (v[i - 1].first + j != v[i].first) ? count_moves(i + 1, 0) : inf;
	b = (v[i - 1].first + j - v[i].first != 1) ? v[i].second + count_moves(i + 1, 1) : inf;
	c = (v[i - 1].first + j - v[i].first != 2) ? 2 * v[i].second + count_moves(i + 1, 2) : inf;
	return dp[i][j] = min(min(a, b), c);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> n; v.clear(); v.resize(n);
		for (auto &x : v) { cin >> x.first >> x.second; }
		for (int i = 0; i <= n; i++) { dp[i][0] = dp[i][1] = dp[i][2] = -1ll; }
		long long m = min(count_moves(1, 0), v[0].second + count_moves(1, 1));
		m = min(2 * v[0].second + count_moves(1, 2), m);
		cout << m << endl;
	}
	cin.ignore(2); return 0;
}