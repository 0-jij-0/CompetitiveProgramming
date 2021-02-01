#include <iostream>
#include <iomanip>
using namespace std;

double dp[1005][501];

double prob(int i, int k) {
	if (dp[i][k] != -1.0) { return dp[i][k]; }
	if (i == 500) { return 1.0; }
	if (abs(i - 500) > k) { return 0.0; }
	double res = prob(i + 1, k - 1) + prob(i - 1, k - 1);
	res /= 2.0; dp[i][k] = res; return res;
}

int main() {
	for (int i = 0; i < 1005; i++)
		for (int j = 0; j < 501; j++)
				dp[i][j] = -1.0;

	int N; cin >> N; double exp = 0.0;
	for (int i = 0; i < 1005; i++) { exp += prob(i, N); }
	cout << setprecision(15) << exp << endl;
	
	cin.ignore(2); return 0;
}