#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 0;

ll fact[5001], choose[2501][2501];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n; cin >> n >> mod; 
	fact[0] = 1; ll res = 0;
	for (int i = 1; i < 5001; i++)
		fact[i] = (i * fact[i - 1]) % mod;

	for (int i = 0; i < 2501; i++) {
		choose[i][0] = choose[i][i] = 1; for (int j = 1; j < i; j++)
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
	}

	if (!(n & 1)) res = fact[n - 2];
	for(int L = n/2; L < n - 1; L++)
		for (int rest = 0; rest < n - L - 1; rest++) {
			ll last = ((n >> 1) << 1) - L;
			ll chooseRest = choose[n - L - 2][rest];
			ll cont = (last * chooseRest) % mod;
			res = (res + cont * fact[L + rest - 1]) % mod;
		}

	cout << (res * n) % mod << '\n';
}