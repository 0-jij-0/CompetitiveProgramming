#include <iostream>
using namespace std;

int n, k, p;
int DP[1005][205][205];

int count_branches(int i, int max, int second_arg) {
	if (DP[i][max][second_arg] != -1) { return DP[i][max][second_arg]; }
	if (i == n) { DP[i][max][second_arg] = 1; return 1; }
	int count = 0;

	for (int j = second_arg; j < max; j++) {
		count += count_branches(i + 1, max, j) % p;
	}
	for (int j = max; j <= k; j++) {
		count += count_branches(i + 1, j, second_arg) % p;
	}

	DP[i][max][second_arg] = count % p;
	return count % p;
}

int count_branches_eff() {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			DP[n][i][j] = 1;
		}
	}
	//DP[x][y][z] = sum[i in range(z, y)](DP[x+1][y][i]) + sum[i in range(y, k+1)](DP[x+1][i][z])
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < k; y++) {
			for (int z = 0; z < k; z++) {

			}
		}
	}
	return 1;
}

int main() {
	cin >> n >> k >> p;

	for (int x = 0; x < n+2; x++) {
		for (int y = 0; y < k+2; y++) {
			for (int z = 0; z < k + 2; z++) {
				DP[x][y][z] = -1;
			}
		}
	}
	cout << count_branches(0, 1, 1) + 1 << endl;
	cin.ignore(2); return 0;
}