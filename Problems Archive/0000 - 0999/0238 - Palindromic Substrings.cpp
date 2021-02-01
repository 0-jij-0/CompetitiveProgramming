#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double dp[5000][5000];
string s; double p = 1.0 / 26.0;

double exp(int i, int j) {
	if (dp[i][j] != -1.0) { return dp[i][j]; }
	if (i >= j) { return 1.0; }
	if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) { return 0.0; }
	if (s[i] != '?' && s[j] != '?') {
		dp[i][j] = exp(i + 1, j - 1); return dp[i][j];
	}
	dp[i][j] = p * exp(i + 1, j - 1);
	return dp[i][j];
}

int main() {
	for (int i = 0; i < 5000; i++)
		for (int j = 0; j < 5000; j++)
			dp[i][j] = -1.0;

	string s1, s2; cin >> s1 >> s2; s1 += s2;
	for (auto x : s1) { if ((x <= 'z' && x >= 'a') || x == '?') { s.push_back(x); } }
	double sum = 0.0;
	for (int i = 0; i < (int)s.size(); i++)
		for (int j = i; j < (int)s.size(); j++)
			sum += exp(i, j);

	cout << setprecision(10) << sum << endl;
	cin.ignore(2); return 0;	
}