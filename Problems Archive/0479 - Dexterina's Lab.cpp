#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

vector<vector<double>> matrix_mult(vector<vector<double>> a, vector<vector<double>> b) {
	int n = (int)a.size();
	vector<vector<double>> c(n, vector<double>(n, 0.0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
	return move(c);
}

vector<vector<double>> matrix_exp(vector<vector<double>> a, int n) {
	vector<vector<double>> I(a.size(), vector<double>(a.size(), 0.0));
	for (int i = 0; i < (int)a.size(); i++) { I[i][i] = 1.0; }
	if (n == 0) { return move(I); }
	if (n == 1) { return move(a); }
	vector<vector<double>> res = matrix_exp(a, n / 2);
	res = matrix_mult(res, res);
	if (n % 2) { return move(matrix_mult(res, a)); }
	return move(res);
}

vector<vector<double>> v;
vector<double> p;

int main() {
	int n, x; cin >> n >> x; 
	int m = (int)ceil(log2(x + 1)); m = (1 << m);
	p.resize(m); v.resize(m, vector<double>(m, 0.0));
	for (int i = 0; i <= x; i++) { cin >> p[i]; }
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			v[i][j] = p[i ^ j];
	v = matrix_exp(v, n);
	cout << fixed << setprecision(7) << 1.0 - v[0][0] << endl;
	cin.ignore(2); return 0;
}