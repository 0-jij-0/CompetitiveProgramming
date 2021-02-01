#include <iostream>
#include <string>
#include <set>
using namespace std;

long long dp[101][101];
string s;

long long subs_count(int i, unsigned int j) {
	if (dp[i][j] != -1) { return dp[i][j]; }
	if (i == 0) { dp[i][j] = 1; return 1; }
	if (j >= s.size()) { dp[i][j] = 0; return 0; }
	
	set<char> st; long long count = 0;
	for (unsigned int k = j; k < s.size() - i + 1; k++) {
		char &c = s[k];
		if (st.find(c) != st.end()) { continue; }
		st.insert(c);
		count += subs_count(i - 1, k + 1);
	}
	dp[i][j] = count; return count;
}

int main() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++) dp[i][j] = -1;

	int n; long long k; cin >> n >> k >> s;
	long long cost = 0;
	for (int i = n; i >= 0; i--) {
		long long x = subs_count(i, 0);
		if (x < k) { cost += (n - i) * x; k -= x; continue; }
		cost += (n - i) * k; k = 0; break;
	}
	if (k != 0) { cout << -1 << endl; }
	else { cout << cost << endl; }
	cin.ignore(2); return 0;
}