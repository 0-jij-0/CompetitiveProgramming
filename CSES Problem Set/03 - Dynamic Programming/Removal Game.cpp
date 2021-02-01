#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> v;
ll dp[2][5001];

int main() {
	int n; cin >> n; v.resize(n); ll sum = 0; 
	for (auto &x : v) { cin >> x; sum += x; }
	for (int i = 0; i < n; i++) dp[1][i] = v[i];

	for (int d = 2; d <= n; d++) for (int i = 0; i <= n - d; i++)
		dp[d & 1][i] = max(v[i] - dp[(d & 1) ^ 1][i + 1], v[i + d - 1] - dp[(d & 1) ^ 1][i]);

	cout << (dp[n & 1][0] + sum) / 2 << endl;
	cin.ignore(2); return 0;
}