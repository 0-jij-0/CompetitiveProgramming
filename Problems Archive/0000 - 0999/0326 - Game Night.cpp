#include <iostream>
#include <string>
using namespace std;

int dp[100001][3][3][3];
int n; string s;

int min_dif(int i, int first, int cur, int past) {
	if (dp[i][first][cur][past] != -1) { return dp[i][first][cur][past]; }
	if (i == n) { return 0; }
	if(cur != first)
}