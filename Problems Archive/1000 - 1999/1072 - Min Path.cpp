#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 61;

struct Matrix {
	int n; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> &_v) : n(_v.size()) { v = move(_v); }
	Matrix(int _n, ll _x) : n(_n), v(_n, vector<ll>(_n, _x)) {}
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
		Matrix res(n), a(v);
		for (; x; x >>= 1, a = a * a)
			if (x & 1) { res = res * a; }
		return move(res);
	}
};

ostream& operator << (ostream &os, Matrix &M) {
	for (auto &x : M.v) { for (auto &y : x) os << y << ' '; os << '\n'; }
	return os;
}

int main() {
	int n, m, k; cin >> n >> m >> k; Matrix M(n, 1ll << 60);
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		u--; v--; M[u][v] = w;
	}
	M = M ^ k; ll res = INF;
	for (auto &x : M.v) { res = min(res, *min_element(x.begin(), x.end())); }
	cout << (res > 1e18 ? "IMPOSSIBLE" : to_string(res)) << endl; 
	cin.ignore(2); return 0;
}