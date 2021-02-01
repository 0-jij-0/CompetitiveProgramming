#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Matrix {
	int n; vector<vector<ll>> v; Matrix() {}
	Matrix(vector<vector<ll>> &_v) : n(_v.size()) { v = _v; }
	Matrix(int &_n, ll _x) : n(_n), v(n, vector<ll>(n, _x)) {}
	vector<ll>& operator[](int idx) { return v[idx]; }

	Matrix operator *(Matrix &rhs) {
		Matrix res(n, -(1 << 29));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					res[i][j] = max(res[i][j], v[i][k] + rhs[k][j]);
		return move(res);
	}
};

Matrix A[9];

Matrix operator ^ (Matrix &M, int &x) {
	Matrix res(M.n, 0); int i = 0; bool b = true;
	for (; x; x >>= 1, i++)
		if (x & 1) { res = b ? A[i] : res * A[i]; b = false; }
	return move(res);
}

bool check(Matrix &M, int k, int &n) {
	Matrix B = M ^ k;
	for (int i = 0; i < n; i++)
		if (B[i][i] > 0) return true;
	return false;
}

int findMin(Matrix &M, int &n) {
	int l = 2, r = n + 1;
	while (l != r) {
		int mid = (l + r) >> 1;
		bool b = check(M, mid, n);
		b ? r = mid : l = mid + 1;
	}
	return (l != n + 1) * l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; Matrix M(n, -(1 << 29));
	for (int i = 0; i < n; i++) M[i][i] = 0;
	for (int i = 0; i < m; i++) {
		int u, v, cu, cv; cin >> u >> v >> cu >> cv;
		u--; v--; M[u][v] = cu; M[v][u] = cv;
	}
	A[0] = M; for (int i = 1; i < 9; i++) { A[i] = A[i - 1] * A[i - 1]; }
	cout << findMin(M, n) << '\n'; cin.ignore(2); return 0;
}