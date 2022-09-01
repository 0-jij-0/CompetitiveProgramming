#include <iostream>
#include <iomanip>
using namespace std;
typedef double ld;

ld DP[1001][1001];

int choose2(int n) { return (n * (n - 1)) >> 1; }

int main() {
	freopen("ballon.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T; while (T--) {
		int N, K; ld P; cin >> N >> K >> P;
		DP[1][0] = 0.0; DP[1][1] = 1.0;
		for (int i = 2; i <= N; i++) {
			DP[i][0] = 0.0; DP[i][i] = 1.0;
			for (int j = 1; j <= min(K, i - 1); j++) {
				ld OO = (choose2(i - j) + 0.0) / choose2(i);
				ld MO = (i - j) * j * P / choose2(i);
				ld OM = (i - j) * j * (1 - P) / choose2(i);
				ld MM = (choose2(j) + 0.0) / choose2(i);
				DP[i][j] = (OO + MO) * DP[i - 1][j] + (OM + MM) * DP[i - 1][j - 1];
			}
		}

		cout << fixed << setprecision(6) << DP[N][K] << '\n';
	}
}