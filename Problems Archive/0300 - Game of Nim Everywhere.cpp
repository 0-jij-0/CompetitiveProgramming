#include <iostream>
#include <string>
using namespace std;

long long dp[62][2][2]; string s;

string binary(int n) {
	string res;
	while (n != 0) { res.push_back(n % 2 + '0'); n /= 2; }
	reverse(res.begin(), res.end()); return res;
}

long long count(int i, int b, bool eq) {
	if (dp[i][b][eq] != -1) { return dp[i][b][eq]; }
	if (i == -1) { return 1ll; }
	if (eq && s[i] == '0')
		return dp[i][b][eq] = count(i + 1, 0, 1);
	if (eq) {
		dp[i][b][eq] = count(i + 1, 0, 0);
		if (i == 0 || s[i - 1] == 0) { dp[i][b][eq] += count(i + 1, 1, 1); }
		return dp[i][b][eq];
	}
	long long res = count(i + 1, 0, 0);
	if (b == 0) { res += count(i + 1, 1, 0); }
	dp[i][b][eq] = res; return res;
}

int main() {
	for(int )
	cin.ignore(2); return 0;
}