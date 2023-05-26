#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll DP[200001][2]; vector<int> A, B;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n; A.resize(n); B.resize(n);
	for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
	DP[0][0] = DP[0][1] = 1;
	for (int i = 1; i < n; i++) {
		DP[i][0] = DP[i][1] = 0;
		if (A[i] != A[i - 1]) DP[i][0] = (DP[i][0] + DP[i - 1][0]) % mod;
		if (A[i] != B[i - 1]) DP[i][0] = (DP[i][0] + DP[i - 1][1]) % mod;
		if (B[i] != A[i - 1]) DP[i][1] = (DP[i][1] + DP[i - 1][0]) % mod;
		if (B[i] != B[i - 1]) DP[i][1] = (DP[i][1] + DP[i - 1][1]) % mod;
	}

	cout << (DP[n - 1][0] + DP[n - 1][1]) % mod << '\n';
}