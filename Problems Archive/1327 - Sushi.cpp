#include <iostream>
#include <iomanip>
using namespace std;
typedef double ld;

ld dp[301][301][301];
int cnt[4]; int n;

int main() {
	cin >> n; dp[0][0][0] = 0.0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x; cnt[x]++;
	}
	for(int z = 0; z <= cnt[3]; z++)
		for(int y = 0; y <= cnt[2] + cnt[3] - z; y++)
			for (int x = 0; x <= n - z - y; x++) if (x + y + z) {
				ld one = x ? (x + 0.0) / (x + y + z + 0.0) * dp[x - 1][y][z] : 0.0;
				ld two = y ? (y + 0.0) / (x + y + z + 0.0) * dp[x + 1][y - 1][z] : 0.0;
				ld thr = z ? (z + 0.0) / (x + y + z + 0.0) * dp[x][y + 1][z - 1] : 0.0;
				dp[x][y][z] = (n + 0.0) / (x + y + z + 0.0) + one + two + thr;
			}
	cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]] << '\n';
	cin.ignore(2); return 0;
}