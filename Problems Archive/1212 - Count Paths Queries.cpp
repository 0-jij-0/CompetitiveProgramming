#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct Matrix {
	int n, m; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> &_v) : n(_v.size()), m(_v.front().size()), v(_v) {}
	Matrix(int _n, int _m, ll _x = 0) : n(_n), m(_m), v(_n, vector<ll>(_m, _x)) {}
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
		return move(res);
	}
};

Matrix power[31]; int n;

vector<ll> mult(vector<ll> &v, Matrix &M) {
	vector<ll> res(v.size(), 0);
	for (int i = 0; i < M.n; i++)
		for (int j = 0; j < M.n; j++)
			res[i] = (res[i] + v[j] * M[j][i]) % mod;
	return move(res);
}

ll query(int &s, int &t, int &k) {
	vector<ll> v(n, 0); v[s] = 1; int i = 1;
	for (; k; k >>= 1, i++) if (k & 1)
		v = mult(v, power[i]);
	return v[t];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int m, q; cin >> n >> m >> q; Matrix M(n, n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--; M[u][v] = 1;
	}
	power[1] = M; for (int i = 2; i < 31; i++)
		power[i] = power[i - 1] * power[i - 1];

	while (q--) {
		int s, t, k; cin >> s >> t >> k;
		cout << query(--s, --t, k) << '\n';
	}

	cin.ignore(2); return 0;
}