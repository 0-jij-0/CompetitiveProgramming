#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double dp[51];
vector<double> prob;
int n;

double exp(int i) {
	if (dp[i] != -1.0) { return dp[i]; }
	if (i >= n - 2) { return 0.0; }
	double b1 = prob[i + 1] * prob[i + 2] * (1 + exp(i + 2));
	double b2 = prob[i + 1] * (1 - prob[i + 2]) * exp(i + 2);
	double b3 = (1 - prob[i + 1]) * exp(i + 1);
	double res = b1 + b2 + b3; dp[i] = res; return res;
}

int main() {
	for (int i = 0; i < 51; i++) { dp[i] = -1.0; }
	char c; cin >> c;
	while (c != '}') {
		int a; cin >> a >> c;
		prob.push_back((a + 0.0) / 100.0);
	}
	n = (int)prob.size();
	cout << setprecision(10) << exp(0) << endl;
	cin.ignore(2); return 0;
}
