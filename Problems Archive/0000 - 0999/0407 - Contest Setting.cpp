#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const long long mod = 998244353;
long long dp[1001][1001];
unordered_map<int, int> m;

long long fill(int i, vector<int>& v, int k) {
	if (dp[i][k] != -1) { return dp[i][k]; }
	if (k == 0) { return 1; }
	if (k > v.size() - i) { return 0; }
	long long ya = (v[i] * fill(i + 1, v, k - 1)) % mod;
	long long no = fill(i + 1, v, k) % mod;
	dp[i][k]= (ya + no) % mod;
	return (ya + no) % mod;
}


int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			dp[i][j] = -1;
	for (int i = 0; i < n; i++) {
		int foo; cin >> foo; m[foo]++;
	}
	vector<int> v;
	for (auto i = m.begin(); i != m.end(); i++)
		v.push_back(i->second);

	if (m.size() < k) { cout << 0 << endl; return 0; }
	cout << fill(0, v, k) << endl;
	cin.ignore(2); return 0;
}
