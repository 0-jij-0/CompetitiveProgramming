#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> p;
vector<int> v;
int k1, k2, k3;

int dp[200005][3];

int min_op(int i, int p) {
	if (dp[i][p] != -1) { return dp[i][p]; }
	if (i == k1 + k2 + k3 + 1) { return 0; }
	int a = (p != 2) ? min_op(i, p + 1) : k1 + k2 + k3 + 5;
	int b = (v[i] != p) + min_op(i + 1, p);
	return dp[i][p] = min(a, b);
}

int main() {
	cin >> k1 >> k2 >> k3; v.resize(k1 + k2 + k3 + 1);
	for (int i = 0; i < k1; i++) {
		int a; cin >> a; v[a] = 0;
	}
	for (int i = 0; i < k2; i++) {
		int a; cin >> a; v[a] = 1;
	}
	for (int i = 0; i < k3; i++) {
		int a; cin >> a; v[a] = 2;
	}

	for (int i = 0; i < k1 + k2 + k3 + 3; i++)
		dp[i][0] = dp[i][1] = dp[i][2] = -1;

	cout << min_op(1, 0) << endl;
	cin.ignore(2); return 0;
}