#include <iostream>
#include <vector>
#include <algorithm>
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, b, k, x; cin >> n >> b >> k >> x;
	Matrix M(x, 0); vector<int> freq(10, 0);
	while (n--) { int y; cin >> y; freq[y % x]++; }

	for (int i = 0; i < x; i++)
		for (int j = 0; j < 10; j++) if (freq[j])
			M[i][(10 * i + j) % x] += freq[j];

	M = M ^ (b - 1); ll res = 0;
	for (int i = 0; i < min(x, 10); i++)
		res = (res + freq[i] * M[i][k]) % mod;
	cout << res << endl; cin.ignore(2); return 0;
}