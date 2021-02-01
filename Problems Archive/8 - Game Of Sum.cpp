#include <iostream>
#include <climits>
using namespace std;

int DP[101][101];


int gameOfSum(int a[], int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];

	if (i == j) {
		DP[i][j] = a[i];
		return DP[i][j];
	}
	int max = INT_MIN;
	int sum = 0;
	for (int k = i; k <= j; k++) {
		sum = sum + a[k];
		int x = sum - gameOfSum(a, k + 1, j);
		max = (max > x) ? max : x;
	}
	sum = 0;
	for (int k = j; k >= i; k--) {
		sum = sum + a[k];
		int x = sum - gameOfSum(a, i, k - 1);
		max = (max > x) ? max : x;
	}
	DP[i][j] = max;
	return DP[i][j];
}

int gameOfSum(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) { DP[i][j] = 0; }
			else { DP[i][j] = -1; }
		}
	}
	return gameOfSum(a, 0, n - 1);
}

int main() {
	int n; cin >> n;
	int a[100];
	while (n != 0) {
		for (int i = 0; i < n; i++) { cin >> a[i]; }
		cout << gameOfSum(a, n) << endl;
		cin >> n;
	}
	cin.ignore(2);
	return 0;
}