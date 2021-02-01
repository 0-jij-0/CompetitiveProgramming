#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct Matrix {
	int n; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> &_v) : n(_v.size()) { v = move(_v); }
	Matrix(int _n, int _x) : n(_n), v(n, vector<ll>(n, 0)) {
		for (int i = 0; i < _n; i++) { v[i][i] = _x; }
	}
	vector<ll>& operator[](int idx) { return v[idx]; }

	Matrix operator *(Matrix &rhs) {
		Matrix res(n, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					res[i][j] = (res[i][j] + v[i][k] * rhs[k][j]) % mod;
		return move(res);
	}
	Matrix operator ^(ll x) {
		Matrix res(n, 1), a(v);
		for (; x; x >>= 1, a = a * a)
			if (x & 1) { res = res * a; }
		return move(res);
	}
};

int main() {
	int n; ll k; cin >> n >> k; 
	vector<int> v(n + 3); Matrix M(n + 3, 0);
	for (int i = n - 1; i >= 0; i--) { cin >> v[i]; }
	for (int i = 0; i < n; i++) { cin >> M[0][i]; }
	for (int i = 1; i < n; i++) { M[i][i - 1] = 1; }
	for (int i = n + 2; i >= n; i--) { cin >> M[0][i]; }
	v[n] = n * n; v[n + 1] = n; v[n + 2] = 1;
	M[n + 2][n + 2] = M[n + 1][n + 2] = M[n][n + 2] = 1;
	M[n + 1][n + 1] = M[n][n] = 1; M[n][n + 1] = 2;
	if (k < n) { cout << v[n - 1 - k] << endl; return 0; }
	M = M ^ (k - n + 1); ll res = 0;
	for (int i = 0; i < n + 3; i++) { res = (res + M[0][i] * v[i]) % mod; }
	cout << res << endl; cin.ignore(2); return 0;
}