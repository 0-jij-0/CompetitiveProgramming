#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) { return power(x, mod - 2); }

struct Matrix {
	int n, m; vector<vector<ll>> v; Matrix() {}
	Matrix(const vector<vector<ll>> &_v) : n(_v.size()), m(_v.front().size()), v(_v) {}
	Matrix(int _n, int _m, ll _x) : n(_n), m(_m), v(_n, vector<ll>(_m, _x)) {}
	Matrix(int _n) : n(_n), m(_n), v(_n, vector<ll>(_n, 0)) {
		for (int i = 0; i < _n; i++) { v[i][i] = 1; }
	}
	vector<ll>& operator[](int idx) { return v[idx]; }

	Matrix operator *(Matrix &rhs) {
		Matrix res(n, rhs.m, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < rhs.m; j++)
				for (int k = 0; k < m; k++)
					res[i][j] = (res[i][j] + v[i][k] * rhs[k][j]) % mod;
		return res;
	}
	Matrix operator ^(ll x) {
		Matrix res(n), a(v); //Change if (*) changes
		for (; x; x >>= 1, a = a * a)
			if (x & 1) { res = res * a; }
		return res;
	}

	//Assumes n = m and computations % mod
	ll getDeterminant() {
		ll res = 1; vector<vector<ll>> M = v;
		for (auto& x : M) for (auto& y : x) y = (y % mod + mod) % mod;

		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n && !M[i][i]; ++j)
				if (M[j][i]) { swap(M[i], M[j]); res = (mod - res) % mod; }

			if (!M[i][i]) { return 0; }
			res = (res * M[i][i]) % mod;

			for (int j = i + 1; j < n; ++j)
				M[i][j] = (M[i][j] * modInv(M[i][i])) % mod;

			for (int j = i + 1; j < n; ++j)	
				if (M[j][i]) for (int x = i + 1; x < n; ++x)
					M[j][x] = (M[j][x] - (M[i][x] * M[j][i]) % mod + mod) % mod;
		}
		return res;
	}
};

int matrixRank(Matrix M) {
	int n = M.n, m = M.m, rank = 0;
	vector<bool> rowVis(n, false);

	for (int i = 0; i < m; i++) {
		int j = 0; for (; j < n; j++) 
			if (!rowVis[j] && M[j][i]) { break; }
		if (j == n) { continue; }
		rank++;	rowVis[j] = true;
		for (int k = i + 1; k < m; k++)	M[j][k] /= M[j][i];
		for (int k = 0; k < n; k++)	if (k != j && M[k][i]) 
				for (int p = i + 1; p < m; ++p)
					M[k][p] -= M[j][p] * M[k][i];
	}
	return rank;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

}