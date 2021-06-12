#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <bitset>
using namespace std;

bitset<2001> dp;
string s;

int main() {
	freopen("binary.in", "r", stdin);
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	int n, x; cin >> n >> x >> s;
	for (int k = 1; k <= n; k++) {
		vector<array<int, 2>> v(k);
		for (int i = 0; i < k; i++) {
			int z = 0, o = 0;
			for (int j = i; j < n; j += k)
				v[i][s[j] == '1']++;
		}

		for (int i = 0; i <= x; i++) dp[i] = 0;
		dp[v[0][0]] = dp[v[0][1]] = 1;
		for (int i = 1; i < k; i++)
			dp = (dp << v[i][0]) | (dp << v[i][1]);

		if (dp[x] == 1) { cout << k << '\n'; break; }
	}

	cin.ignore(2); return 0;
}