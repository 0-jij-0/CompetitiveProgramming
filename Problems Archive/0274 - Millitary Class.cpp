#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long dp[2001][550];
vector<pair<int, int>> cons;
int n, e, k;
const long long mod = (1000 * 1000 * 1000) + 7;

long long matching_num(int i, int mask) {
	if (dp[i][mask] != -1) { return dp[i][mask]; }
	if (i == n) { return 1ll; }

	long long res = 0; int m = 1 << 2 * e;
	int b = i - e, r = (i + e < n - 1) ? i + e : n - 1;
	while (b < 0) { b++; m >>= 1; }

	while (b <= r) {
		if (m & mask) { b++; m >>= 1; continue; }
		pair<int, int> p(i + 1, b + 1);
		if (binary_search(cons.begin(), cons.end(), p)) { b++; m >>= 1; continue; }
		int new_mask = ((mask | m) << 1) % (1 << (2 * e + 1));
		res += matching_num(i + 1, new_mask); res %= mod;
		if (m == 1 << 2 * e) { dp[i][mask] = res; return res; }
		m >>= 1; b++;
	}
	dp[i][mask] = res; return res;
}

void resetDP() {
	for (int i = 0; i < 2001; i++)
		for (int j = 0; j < 550; j++)
			dp[i][j] = -1;
}

int main() {
	cin >> n >> e >> k;	cons.resize(k);
	for (auto &x : cons) { cin >> x.first >> x.second; }
	sort(cons.begin(), cons.end()); resetDP();
	cout << matching_num(0, 0) << endl;

	cin.ignore(2); return 0;
}