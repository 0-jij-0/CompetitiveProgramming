#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
long long dp[100005][2];
int n;

long long max_height(int i, bool t) {
	if (dp[i][t] != -1) { return dp[i][t]; }
	if (i == n) { dp[i][t] = 0; return 0; }
	long long a = v[t][i] + max_height(i + 1, !t);
	long long b = (i + 1 != n) ? v[t][i + 1] + max_height(i + 2, !t) : -1;
	long long m = (a < b) ? b : a; 
	dp[i][t] = m; return m;
}

int main() {
	cin >> n; v.resize(2);
	v[0].resize(n); v[1].resize(n);
	for (int i = 0; i < n + 1; i++) { dp[i][0] = dp[i][1] = -1; }
	for (int i = 0; i < n; i++) { cin >> v[0][i]; }
	for (int i = 0; i < n; i++) { cin >> v[1][i]; }
	long long c1 = max_height(0, 0), c2 = max_height(0, 1);
	long long m = (c1 < c2) ? c2 : c1;
	cout << m << endl;
	cin.ignore(2); return 0;
}