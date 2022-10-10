#include <bits/stdc++.h>
using namespace std;

int DP[100][100];

int find(int i, int j, int n) {
	if (n == 0) return 0;

	int m = n >> 1;
	if (i < m && j < m) return find(i, j, m);
	if (i >= m && j >= m) return find(i - m, j - m, m);
	return m + find(i -(i >= m) * m, j - (j >= m) * m, m);
}

int main() {
	int x, y; cin >> x >> y;
	cout << find(--x, --y, 1 << 30) << '\n';
}