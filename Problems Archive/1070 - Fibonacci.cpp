#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<vector<ll>> matrixMult(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	int n = (int)a.size();
	vector<vector<ll>> c(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
	return move(c);
}

vector<vector<ll>> matrixExp(vector<vector<ll>> &a, ll n) {
	vector<vector<ll>> I(a.size(), vector<ll>(a.size(), 0));
	for (int i = 0; i < (int)a.size(); i++) { I[i][i] = 1; }
	if (n == 0) { return move(I); }
	if (n == 1) { return a; }
	vector<vector<ll>> res = matrixExp(a, n / 2);
	res = matrixMult(res, res);
	if (n % 2) { return move(matrixMult(res, a)); }
	return move(res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	vector<vector<ll>> matrix = { {0, 1}, {1, 1} };
	cout << matrixExp(matrix, n)[0][1] << endl;
	cin.ignore(2); return 0;
}