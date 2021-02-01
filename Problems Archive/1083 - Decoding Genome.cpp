#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

struct Matrix {
	int n; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> &_v) : n(_v.size()) { v = move(_v); }
	Matrix(int _n, ll _x) : n(_n), v(n, vector<ll>(n, _x)) {}
	Matrix(int _n) : n(_n), v(n, vector<ll>(n, 0)) {
		for (int i = 0; i < _n; i++) { v[i][i] = 1; }
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
		Matrix res(n), a(v);
		for (; x; x >>= 1, a = a * a)
			if (x & 1) { res = res * a; }
		return move(res);
	}
};

inline bool isUpper(char &c) { return c >= 'A' && c <= 'Z'; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; int m, k; cin >> n >> m >> k;
	Matrix M(m, 1); for (int i = 0; i < k; i++) {
		char a, b; cin >> a >> b;
		int u = isUpper(a) ? 26 + a - 'A' : a - 'a';
		int v = isUpper(b) ? 26 + b - 'A' : b - 'a';
		M[u][v] = 0;
	}
	//for (auto &x : M.v) { for (auto &y : x) cout << y; cout << '\n'; }
	M = M ^ (n - 1); ll res = 0;
	//for (auto &x : M.v) { for (auto &y : x) cout << y; cout << '\n'; }
	for (auto &x : M.v) for (auto &y : x) res = (res + y) % mod;
	cout << res << endl; cin.ignore(2); return 0;
}