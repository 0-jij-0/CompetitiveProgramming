#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[26] = { 0 };
string s; int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> s; n = (int)s.size();
	int sum = 0; for (char& c : s) {
		int temp = (sum - dp[c - 'a'] + mod) % mod;
		dp[c - 'a'] = sum + 1; sum = (temp + dp[c - 'a']) % mod;
	}

	cout << sum << '\n';
}