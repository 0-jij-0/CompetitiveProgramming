#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1000 * 1000 * 1000 + 7;

ll S[5001][5001], C[5001][5001], powN[5001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; vector<ll> res(n); powN[0] = 1;
	fill(S[0], S[0] + 5001 * 5001, 0); S[0][0] = 1;
	fill(C[0], C[0] + 5001 * 5001, 1); 

	for (int i = 1; i <= 5000; i++) {
		powN[i] = (n * powN[i - 1]) % mod; 
		S[i][i] = 1; for (int j = 1; j < i; j++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
			S[i][j] = ((i - 1) * S[i - 1][j] + S[i - 1][j - 1]) % mod;
		}
	}

	for (int i = 1; i <= n; i++) res[i - 1] = S[n][i];
	for (int k = 1; k <= n; k++) 
		for (int x = 1; x < n; x++) {
			ll ans1 = (C[n][x] * S[x][k]) % mod;
			ll ans2 = (x * powN[n - x - 1]) % mod;
			res[k - 1] = (res[k - 1] + ans1 * ans2) % mod;
		}

	for (auto& x : res) cout << x << '\n';
}