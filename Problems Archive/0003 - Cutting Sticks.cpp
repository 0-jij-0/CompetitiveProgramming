#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int DP[1000][1000];

int DPcutSticks(int a[], int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }

	int min = INT_MAX;
	for (int k = i + 1; k < j; k++) {
		int x = DPcutSticks(a, i, k);
		int y = DPcutSticks(a, k, j);
		int t = a[j] - a[i] + x + y;
		min = (min < t) ? min : t;
	}
	DP[i][j] = min;
	return DP[i][j];
}

int cutSticks(int a[], int l, int n) {
	if (n <= 0) return 0;

	sort(a, a + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + 1 >= j) { DP[i][j] = 0; }
			else { DP[i][j] = -1; }
		}
	}
	return DPcutSticks(a, 0, n - 1);
}

int main() {

	int l; cin >> l;
	while (l != 0) {
		int n; cin >> n;

		int *a = new int[n + 2];
		a[0] = 0;
		for (int i = 1; i < n + 1; i++) {
			cin >> a[i];
		}
		a[n + 1] = l;
		cout << cutSticks(a, l, n + 2);
		cin >> l;
	}

	cout << endl; cin.ignore(2); return 0;
}