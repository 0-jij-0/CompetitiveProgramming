#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<unordered_map<int, ll>> L, R;
vector<vector<int>> G; int n;

int countBits(int x) {
	int res = 0; 
	for (; x; x &= (x - 1), ++res);
	return res;
}

int getXOR(int i, int j, int mask) {
	int res = G[i][j];
	for (int k = 0; k < n - 1; k++, res ^= G[i][j]) 
		(mask & (1 << k) ? i : j)++;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; L.resize(n); R.resize(n);
	G.resize(n, vector<int>(n));
	for (auto& x : G) for (auto& y : x) cin >> y;

	for (int i = 0; i < (1 << (n - 1)); i++) {
		int D = countBits(i);
		L[D][getXOR(0, 0, i)]++;
		R[n - 1 - D][getXOR(n - 1 - D, D, i)]++;
	}

	ll res = 0;
	for (int i = 0; i < n; i++)	for (auto& [x, s] : L[i]) 
		res += s * R[i][x ^ G[i][n - 1 - i]];

	cout << res << '\n';
}