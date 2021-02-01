#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int dp[11][11][11][11];
int a[10]; ll sum;
int valid[11];
int v[10][11];

bool makeDiv11(int d, int s, int l, int r) {
	if (d == 10) { return !s && valid[l] == r && l == ((r + (sum & 1)) % 11); }
	if (dp[d][s][l][r] != -1) { return dp[d][s][l][r]; }
	if (a[d] == 0) { return dp[d][s][l][r] = makeDiv11(d + 1, s, l, r); }
	for (int i = 0; i < 11; i++)
		if (i + v[d][i] <= a[d]) {
			int new_s = ((s + i * d - v[d][i] * d) + 110) % 11;
			int new_l = (l + i) % 11, new_r = (r + v[d][i]) % 11;
			bool b = makeDiv11(d + 1, new_s, new_l, new_r);
			if (b) { return dp[d][s][l][r] = true; }
		}
	return dp[d][s][l][r] = false;
}

void resetDP() {
	for (int i = 0; i < 11; i++)
		valid[i] = (((sum % 11) - i) + 11) % 11;
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 11; j++)
			v[i][j] = (((a[i] % 11) - j) + 11) % 11;

	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			for (int k = 0; k < 11; k++)
				for (int l = 0; l < 11; l++)
					dp[i][j][k][l] = -1;
}

int main() {
	int t; cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		sum = 0; for (int i = 1; i < 10; i++) { cin >> a[i]; sum += a[i]; }
		cout << "Case #" << tc << ": ";
		resetDP(); bool b = makeDiv11(1, 0, 0, 0);
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}