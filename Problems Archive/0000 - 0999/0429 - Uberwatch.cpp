#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> op;
int DP[300004][11];
int n, M;

int maxKill(int d, int m) {
	if (DP[d][m] != -1) { return DP[d][m]; }
	if (d == n) { return DP[d][m] = 0; }

	int res = 0;
	if (m == 0) {
		int c1 = maxKill(d + 1, 0);
		int c2 = op[d] + maxKill(d + 1, M - 1);
		res = max(res, c1);
		res = max(res, c2);
	}
	else {
		res = maxKill(d + 1, m - 1);
	}

	DP[d][m] = res;
	return DP[d][m];
}

void resetDP() {
	for (int i = 0; i < 300004; i++)
		for (int j = 0; j < 11; j++)
			DP[i][j] = -1;
}

int main() {
	cin >> n >> M;
	op.resize(n);
	for (auto &x : op) { cin >> x; }
	resetDP();

	cout << maxKill(0, M);
}