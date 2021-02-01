#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll dp[51][51];
vector<int> v;

ll countWays(int i, int j) {
	if (i >= j) { return 1; }
	if (i + 1 == j) { return 1 + (v[i] == v[j]); }
	if (dp[i][j] != -1) { return dp[i][j]; }

	int p = 0; ll res = 1;
	for (int x = i; x < j; x++) {
		p += v[x]; int s = 0;
		for (int y = j; y > x; y--) {
			s += v[y]; if (s != p) { continue; }
			res = (res + countWays(x + 1, y - 1)) % mod;
		}
	}
	return dp[i][j] = res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s; v.resize(s.size());
		int n = (int)s.size();
		for (int i = 0; i < n; i++) { v[i] = s[i] - '0'; }
		memset(dp, -1, sizeof(dp));
		cout << countWays(0, n - 1) << endl;
	}
	cin.ignore(2); return 0;
}