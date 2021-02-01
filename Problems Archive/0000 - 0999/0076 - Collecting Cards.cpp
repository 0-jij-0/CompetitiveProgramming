#include <iostream>
#include <iomanip>
using namespace std;

int c, n;
double DP[50];
long long nCk[41][41];

void fill_nCk(){
	nCk[0][0] = 1;
	for (int i = 1; i < 41; i++) { nCk[i][0] = 1; nCk[i][i] = 1; }
	for (int i = 2; i < 41; i++) {
		for (int j = 1; j < i; j++) {
			nCk[i][j] = nCk[i - 1][j] + nCk[i - 1][j - 1];
		}
	}
}

double p(int i, int idx) {
	double ans = ((nCk[c - i][idx] * nCk[i][n - idx]) + 0.0) / (nCk[c][n] + 0.0);
	return ans;
}

double E(int i) {
	if (DP[i] != -1.0) { return DP[i]; }
	if (i == c) { return 0.0; }
	int low = n - i; int high = (n < c - i) ? n : c - i; 
	double sum = 1.0; int idx = (low > 0) ? low : 1;
	
	for (; idx <= high; idx++) {
		sum += p(i, idx)*E(idx + i);
	}
	if (low <= 0) { sum /= 1 - p(i, 0); }
	DP[i] = sum; return sum;
}

int main() {
	fill_nCk();
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> c >> n;
		for (int j = 0; j < c + 1; j++) { DP[j] = -1.0; }
		cout << "Case #" << i << ": " << E(0) << endl;
	}
	return 0;
}