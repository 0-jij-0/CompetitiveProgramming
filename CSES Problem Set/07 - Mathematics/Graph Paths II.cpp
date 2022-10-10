#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 61;

struct Matrix {
	int n; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> &_v) : n(_v.size()) { v = _v; }
	Matrix(int _n, ll _x) : n(_n), v(n, vector<ll>(n, _x)) {}
	Matrix(int _n) : n(_n), v(n, vector<ll>(n, 0)) {
		for (int i = 0; i < _n; i++) { v[i][i] = 1; }
	}
	vector<ll>& operator[](int idx) { return v[idx]; }
	Matrix operator *(Matrix &rhs) {
		Matrix res(n, INF);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					res[i][j] = min(res[i][j], v[i][k] + rhs[k][j]);
		return move(res);
	}
	Matrix operator ^(ll x) {
		Matrix res(n, 0), a(v); bool b = false;
		for (; x; x >>= 1, a = a * a) {
			if ((x & 1) && !b) { res = a; b = true; continue; }
			if (x & 1) { res = res * a; }
		}
		return move(res);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m, k; cin >> n >> m >> k; Matrix M(n, INF);
	for (int i = 0; i < m; i++) {
		int u, v; ll c; cin >> u >> v >> c;
		u--; v--; M[u][v] = min(M[u][v], c);
	}
	M = M ^ k; ll res = M[0].back();
	cout << (res > 1e18 ? -1 : res) << '\n';
}