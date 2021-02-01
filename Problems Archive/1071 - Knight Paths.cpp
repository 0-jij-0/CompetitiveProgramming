#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int ll;

vector<vector<ll>> matrixMult(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	int n = (int)a.size();
	vector<vector<ll>> c(n, vector<ll>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
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

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int main() {
	int k; cin >> k;
	vector<vector<ll>> v(65, vector<ll>(65, 0));
	for(int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++) {
				if (i + dx[k] < 0 || i + dx[k] > 7) { continue; }
				if (j + dy[k] < 0 || j + dy[k] > 7) { continue; }
				int a = i * 8 + j, b = (i + dx[k]) * 8 + j + dy[k];
				v[a][b] = 1;
			}
	for (int i = 0; i < 65; i++) { v[i][64] = 1; }
	v = matrixExp(v, k); ll res = 0;
	for (auto &x : v[0]) { res += x; }
	cout << res << endl; cin.ignore(2); return 0;
}