#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> pre;
vector<int> v;
long long dp[52][52];
long long C[51][51];
const long long mod = 1000000007;

void fill_nck() {
	C[0][0] = 1;
	for (int i = 1; i < 51; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
}

bool b(int x, int i, int j) {
	return x == pre[i][j].first || x == pre[i][j].second;
}

long long count(int i, int j) {
	if (dp[i][j] != -1) { return dp[i][j]; }
	if (i + 1 == j) { dp[i][j] = v[i] > v[j]; return dp[i][j]; }
	
	long long res = 0;
	int &x = pre[i][j].first, &y = pre[i][j].second;

	if (i + 1 == v[i]) { res += count(i + 1, j); res %= mod; }
	if (j - 1 == v[j]) { res += count(i, j - 1); res %= mod; }

	for (int k = i + 1; k < j - 1; k++) {
		if (b(x, i, k) && b(k + 1, i, k) && b(k, k + 1, j) && b(y, k + 1, j)) {
			long long a = count(i, k); a %= mod;
			long long b = count(k + 1, j); b %= mod;
			long long c = (a * b) % mod; 
			res += (C[j - i - 1][k - i] * c) % mod; res %= mod;
		}
	}
	dp[i][j] = res; return res;
}

int main() {
	char c; cin >> c;
	while (c != '}') {
		int a; cin >> a >> c;
		v.push_back(a);
	}
	int n = (int)v.size(); pre.resize(n);
	for (int i = 0; i < n; i++) { pre[i].resize(n); }
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			set<int> s;
			for (int x = i; x <= j; x++) { s.insert(v[x]); }
			for (int x = i + 1; x < j; x++) { s.erase(x); }
			if (s.size() != 2) { pre[i][j] = { -1, -1 }; }
			else { pre[i][j] = { *s.begin(), *s.rbegin() }; }
		}
	}

	fill_nck();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
					dp[i][j] = -1;

	cout << count(0, n - 1) << endl;

	cin.ignore(2); return 0;
}