#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 10;

struct Matrix {
	int n, m; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>>& _v) : n(_v.size()), m(_v.front().size()), v(_v) {}
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
	freopen("hack.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string p; int n; cin >> p >> n;
		int m = (int)p.size(); Matrix M(m, m, 0);
		for (int i = 0; i < m; i++) {
			if (i == 0) { M[i][i] = 1; continue; }
			if (i + 1 == m) { M[i][i] = 1; continue; }
			M[i][i - 1] = M[i][i + 1] = 1;
		}

		M = M ^ n; for (int i = 0; i < m; i++) {
			int d = 0; for (int j = 0; j < m; j++)
				d = (d + M[i][j] * (p[j] - '0')) % mod;
			cout << d; if (i + 1 == m) cout << '\n';
		}
	}

	cin.ignore(2); return 0;
}