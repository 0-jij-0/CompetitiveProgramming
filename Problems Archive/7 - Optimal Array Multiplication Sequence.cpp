#include <iostream>
#include <string>
using namespace std;

int DP[15][15];
int CA[15][15];

int DPnumOfMult(int a[10][2], int i, int j) {
	if (DP[i][j] != -1) { return DP[i][j]; }

	if (i + 1 == j) { 
		CA[i][j] = i;
		DP[i][j] = a[i][0] * a[i][1] * a[j][1];
		return DP[i][j];
	}

	int min = 1000000000;
	CA[i][j] = i;
	for (int k = i; k < j; k++) {
		int x = (a[i][0] * a[k][1] * a[j][1]) + DPnumOfMult(a, i, k) + DPnumOfMult(a, k + 1, j);
		if (x < min) {
			min = x;
			CA[i][j] = k;
		}
	}
	DP[i][j] = min;
	return DP[i][j];
}

string matrixMult(int i, int j) {
	if (i == j) { 
		if (i == 9) return "A10";
		else {
			string res = "A0";
			res[1] = i + '1';
			return res;
		}
	}
	int k = CA[i][j];

	string res ="(" + matrixMult(i, k) + " x " + matrixMult(k + 1, j) + ")";
	return res;
}

void optMult(int a[10][2], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i >= j) { DP[i][j] = 0; }
			else { DP[i][j] = -1; }
		}
	}
	int b = DPnumOfMult(a, 0, N - 1);
	cout << matrixMult(0, N - 1);
}

int main() {
	int N; cin >> N;
	int itt = 1;
	while (N != 0){
		int a[10][2];
		for (int i = 0; i < N; i++) { cin >> a[i][0] >> a[i][1]; }
		cout << "Case " << itt << ": "; optMult(a, N);
		cout << endl; cin >> N; itt++;
	}
	cin.ignore(2);
	return 0;
}

