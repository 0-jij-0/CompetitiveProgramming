#include <iostream>
using namespace std;

int **arr;

int recWays(int a, int b) {

	if (arr[a][b] != -1) { return arr[a][b]; }
	
	if (a == 0 && b == 0) { return 0; }

	else if (a == 0) { arr[0][b] = 1; return 1; }

	else if (b == 0) { arr[a][0] = recWays(a - 1, 1);  return arr[a][0]; }

	arr[a][b] = recWays(a - 1, b + 1) + recWays(a, b - 1);

	return arr[a][b];
}

int numOfWays(int n) {

	arr = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) { arr[i] = new int[n + 1]; }
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 1; j++) { arr[i][j] = -1; }
	}
	arr[0][0] = 1;

	return recWays(n, 0);
}

int main() {
	for (int i = 1; i < 6; i++) {
		cout << numOfWays(i) << endl;
	}
	cin.ignore(2);
	return 0;
}
