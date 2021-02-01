#include <iostream>
using namespace std;

int recKS(int a[][2], int n, int c) {
	if (n == 0 || c == 0) return 0;
	if (a[n][0] > c) return recKS(a, n - 1, c);
	int temp1 = recKS(a, n - 1, c);
	int temp2 = a[n][1] + recKS(a, n - 1, c - a[n][0]);
	return (temp1 > temp2) ? temp1 : temp2;
}

int DPKS(int **a, int **arr, int n, int c) {
	if (arr[n][c] != -1) return arr[n][c];
	if (a[n][0] > c) arr[n][c] = DPKS(a, arr, n - 1, c);
	else {
		int temp1 = DPKS(a, arr, n-1, c);
		int temp2 = a[n][1] + DPKS(a, arr, n - 1, c - a[n][0]);
		arr[n][c] = (temp1 > temp2) ? temp1 : temp2;
	}
	return arr[n][c];
}

int KS(int **a, int n, int c) {
	int **arr = new int *[n+1];
	for (int i = 0; i < n + 1; i++) { arr[i] = new int[c + 1]; }
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < c + 1; j++) { arr[i][j] = -1; }
	}
	for (int i = 0; i < n + 1; i++) arr[i][0] = 0;
	for (int i = 0; i < c + 1; i++) arr[0][i] = 0;

	int res = DPKS(a, arr, n, c);
	delete arr;
	return res;

}

int main() {

	int n, s;
	cin >> s >> n;
	int **a = new int* [n+1];
	for (int i = 0; i < n + 1; i++) { a[i] = new int[2]; }
	a[0][0] = 0; a[0][1] = 0;
	for (int i = 1; i < n + 1; i++) { cin >> a[i][0] >> a[i][1]; }

	cout << KS(a, n, s);
	cin.ignore(2);
	return 0;
}