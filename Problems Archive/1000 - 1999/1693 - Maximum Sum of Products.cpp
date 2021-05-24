#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> A, B;
ll dp[5001][5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; A.resize(n); B.resize(n);
	for (auto& x : A) { cin >> x; }
	for (auto& x : B) { cin >> x; }

	ll totalSum = 0;
	for (int i = 0; i < n; i++)
		totalSum += A[i] * B[i];

	dp[0][0] = totalSum; for (int i = 1; i < n; i++) 
		dp[i][i - 1] = dp[i][i] = totalSum;

	ll res = totalSum; for(int len = 1; len < n; len++)
		for (int i = 0; i < n - 1; i++) {
			if (i + len == n) { break; }
			ll add = A[i] * B[i + len] + A[i + len] * B[i];
			ll sub = A[i] * B[i] + A[i + len] * B[i + len];
			res = max(res, dp[i][i + len] = dp[i + 1][i + len - 1] - sub + add);
		}

	cout << res << '\n';
	cin.ignore(2); return 0;
}