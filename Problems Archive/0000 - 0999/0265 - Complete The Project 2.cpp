#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> pos, neg;
int dp[101][60001];

int check_pos(int &r) {
	int res = 0;
	for (auto &x : pos) {
		if (x.first > r) { return res; }
		r += x.second; res++;
	}
	return res;
}

bool compare(const pair<int, int> &p1, const pair<int, int> &p2) {
	return (p1.first + p1.second) < (p2.first + p2.second);
}

int check_neg(int i, int r) {
	if (dp[i][r] != -1) { return dp[i][r]; }
	if (i == (int)neg.size()) { return 0; }

	int a = check_neg(i + 1, r);
	int b = (r >= neg[i].first) ? 1 + check_neg(i + 1, r + neg[i].second) : 0;
	dp[i][r] = max(a, b); return dp[i][r];	
}

void resetDP() {
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 60001; j++)
			dp[i][j] = -1;
}

int main() {
	int n, r; cin >> n >> r;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		pair<int, int>p(a, b);
		((b < 0) ? neg : pos).push_back(p);
	}
	sort(pos.begin(), pos.end());
	for (auto &x : neg) { x.first = max(x.first, -x.second); }
	sort(neg.rbegin(), neg.rend(), compare);
	resetDP();

	int res = check_pos(r);
	res += check_neg(0, r);
	cout << res << endl;

	cin.ignore(2); return 0;
}