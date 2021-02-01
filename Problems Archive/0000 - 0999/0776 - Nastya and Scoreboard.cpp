#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector<string> digits = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
vector<string> v;

int dp[2001][2001]; int n;

int xorStr(string &a, string &b) {
	int res = 0;
	for (int i = 0; i < 7; i++) {
		if (a[i] == '1' && b[i] == '0') { return 100000; }
		res += a[i] != b[i];
	}
	return res;
}

int maxDigit(int i, int k) {
	if (i == n && k == 0) { return 1; }
	if (i == n) { return -2; }
	if (dp[i][k] != -1) { return dp[i][k]; }

	int res = -2;
	for (int j = 0; j < 10; j++) {
		int x = xorStr(v[i], digits[j]);
		if (x > k) { continue; }
		if (maxDigit(i + 1, k - x) >= 0) { res = j; }
	}
	return dp[i][k] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int k; cin >> n >> k; v.resize(n);
	for (auto &x : v) { cin >> x; }
	memset(dp, -1, sizeof(dp));
	maxDigit(0, k);
	if (dp[0][k] == -2) { cout << -1 << endl; return 0; }
	for (int i = 0; i < n; i++) {
		cout << dp[i][k]; k -= xorStr(v[i], digits[dp[i][k]]);
	}
	cout << endl; cin.ignore(2); return 0;
}