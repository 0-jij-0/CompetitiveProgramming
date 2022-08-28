#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<int> T, X, A;
ll dp[100001][5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; T.resize(n); X.resize(n); A.resize(n);
	for (int i = 0; i < n; i++) cin >> T[i] >> X[i] >> A[i];
	dp[0][0] = 0; for (int i = 1; i < 5; i++) dp[0][i] = -(1ll << 60);

	int t = 0; for (int i = 1; t < n; i++) {
		if (i != T[t]) for (int j = 0; j < 5; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
			if (j != 4) dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
		}
		else {
			for (int j = 0; j < 5; j++) {
				dp[i][j] = (j == X[t] ? A[t] : 0) + dp[i - 1][j];
				if (j) dp[i][j] = max(dp[i][j], (j == X[t] ? A[t] : 0) + dp[i - 1][j - 1]);
				if (j != 4) dp[i][j] = max(dp[i][j], (j == X[t] ? A[t] : 0) + dp[i - 1][j + 1]);
			}
			t++;
		}
	}

	cout << *max_element(dp[T[n - 1]], dp[T[n - 1]] + 5) << '\n';
}