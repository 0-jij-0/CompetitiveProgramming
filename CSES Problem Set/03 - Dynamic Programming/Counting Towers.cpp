#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct Matrix {
	int n, m; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> _v) : n(_v.size()), m(_v.front().size()), v(_v) {}
	Matrix(int _n, int _m, ll _x) : n(_n), m(_m), v(_n, vector<ll>(_m, _x)) {}
	Matrix(int _n) : n(_n), m(_n), v(_n, vector<ll>(_n, 0)) {
		for (int i = 0; i < _n; i++) { v[i][i] = 1; }
	}
	vector<ll>& operator[](int idx) { return v[idx]; }

	Matrix operator *(Matrix& rhs) {
		Matrix res(n, rhs.m, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < rhs.m; j++)
				for (int k = 0; k < m; k++)
					res[i][j] = (res[i][j] + v[i][k] * rhs[k][j]) % mod;
		return move(res);
	}
	Matrix operator ^(ll x) {
		Matrix res(n), a(v); //Change if (*) changes
		for (; x; x >>= 1, a = a * a)
			if (x & 1) { res = res * a; }
		return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Matrix G({ {4, 1}, {1, 2} });
	int t; cin >> t; while (t--) {
		int n; cin >> n; Matrix M = G ^ (n - 1);
		cout << (M[0][0] + M[0][1] + M[1][0] + M[1][1]) % mod << '\n';
	}
}