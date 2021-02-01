#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int MOD = 1000 * 1000 * 1000 + 7;

int dp[2][100][2]; string S;
inline int s(int i) { return S[i] - '0'; }

int main() {
	int d; cin >> S >> d; int n = (int)S.size();
	fill(dp[0][0], dp[0][0] + 400, 0); dp[0][0][1] = 1;
	for (int i = 0; i < n; i++) {
		int I = (i ^ 1) & 1;
		fill(dp[I][0], dp[I][0] + 200, 0);
		for (int k = 0; k < d; k++) {
			for (int j = 0; j < 10; j++) {
				int K = (k + j) % d;
				dp[I][K][0] = (dp[I][K][0] + dp[i & 1][k][0]) % MOD;
				if (s(i) > j) {	dp[I][K][0] = (dp[I][K][0] + dp[i & 1][k][1]) % MOD; }
				if (s(i) == j) { dp[I][K][1] = (dp[I][K][1] + dp[i & 1][k][1]) % MOD; }
			}
		}
	}
	cout << (dp[n & 1][0][1] + dp[n & 1][0][0] - 1 + MOD) % MOD << '\n';
	cin.ignore(2); return 0;
}