#include <iostream>
#include <set>
#include <string>
using namespace std;

int dp[51]; int n, k;

int mex(int i) {
	if (dp[i] != -1) { return dp[i]; }
	if (i <= k) { return (i == k); }
	set<int> s; int x = i - k;
	for (int j = 0; j <= x / 2; j++) {
		s.insert(mex(j) ^ mex(x - j));
	}
	int res = 0;
	for (auto &it : s) {
		if (it == res) { res++; }
		else { break; }
	}
	dp[i] = res; return res;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 51; j++) { dp[j] = -1; }
		cin >> n >> k;
		string s = (mex(n) == 0) ? "Losing" : "Winning";
		cout << "Case " << i + 1 << ": " << s << endl;
	}
	cin.ignore(2); return 0;
}