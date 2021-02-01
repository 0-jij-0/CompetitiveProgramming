#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<string> v;
ll dp[2001][2001], vert[2001][2001], hori[2001][2001], diag[2001][2001];

int main() {
	int h, w; cin >> h >> w; v.resize(h, string(w, '.'));
	for (auto& x : v) for (char& c : x) cin >> c;

	dp[0][0] = vert[0][0] = hori[0][0] = diag[0][0] = 1;
	for(int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			if (i + j == 0) { continue; }
			if (v[i][j] == '#') { dp[i][j] = vert[i][j] = hori[i][j] = diag[i][j] = 0; continue; }
			if (i) { dp[i][j] = (dp[i][j] + vert[i - 1][j]) % mod; }
			if (j) { dp[i][j] = (dp[i][j] + hori[i][j - 1]) % mod; }
			if (i && j) { dp[i][j] = (dp[i][j] + diag[i - 1][j - 1]) % mod; }

			vert[i][j] = i ? (vert[i - 1][j] + dp[i][j]) % mod : dp[i][j];
			hori[i][j] = j ? (hori[i][j - 1] + dp[i][j]) % mod : dp[i][j];
			diag[i][j] = i && j ? (diag[i - 1][j - 1] + dp[i][j]) % mod : dp[i][j];
		}

	cout << dp[h - 1][w - 1] << '\n';
	cin.ignore(2); return 0;
}