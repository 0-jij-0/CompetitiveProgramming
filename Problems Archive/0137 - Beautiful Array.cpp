#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long DP[300001][4];
int n, x;
int mult[4] = { 0, 1, -1, 1 };
vector<long long> v;

long long max_beauty(int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }
	if (j == 4 || i == n) { DP[i][j] = 0; return 0; }

	long long a = 0, b = 0, c = 0;
	a = mult[j] * v[i] + max_beauty(i + 1, j);
	if (j < 3) { b = mult[j + 1] * v[i] + max_beauty(i + 1, j + 1); }
	if (j < 2) { c = mult[j + 2] * v[i] + max_beauty(i + 1, j + 2); }
	long long m = max(b, a); m = max(m, c);
	DP[i][j] = m; return m;
}

int main() {
	cin >> n >> x; mult[2] = x; v.resize(n);
	for (int i = 0; i < n + 1; i++) 
		for (int j = 0; j < 4; j++) 
			DP[i][j] = -1;
	for (auto &x : v) { cin >> x; }
	cout << max_beauty(0, 0) << endl;
	cin.ignore(2); return 0;
}