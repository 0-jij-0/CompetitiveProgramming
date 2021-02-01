#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
using namespace std;

int dp[1000][1000];
int choice[1000][1000];
vector<int> w, s, idx; int n;

int LIS(int i, int last) {
	if (i == n) { return 1; }
	if (dp[i][last] != -1) { return dp[i][last]; }

	int a = LIS(i + 1, last), b = 0;
	if (w[idx[i]] > w[idx[last]] && s[idx[i]] < s[idx[last]])
		b = 1 + LIS(i + 1, i);
	choice[i][last] = (a > b) ? 0 : 1;
	return dp[i][last] = max(a, b);
}

bool compare(const int &x1, const int &x2) {
	return w[x1] < w[x2];
}

int main() {
	fill(dp[0], dp[0] + 1000 * 1000, -1);
	fill(choice[0], choice[0] + 1000 * 1000, -1);
	while (true) {
		string str; getline(cin, str);
		if (str == "") { break; }
		stringstream ss(str);
		int W, S; ss >> W >> S;
		w.push_back(W); s.push_back(S);
	}
	n = (int)w.size(); int res = 0;
	idx.resize(n); iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), compare);

	for (int i = 0; i < n; i++)
		res = max(res, LIS(i + 1, i));

	cout << res << endl; int cur = 1, last = 0;
	while (dp[cur][last] != res) { cur++; last++; }
	cout << idx[last] + 1 << endl; res--;
	while (res) {
		if (choice[cur][last] == 0) { cur++; continue; }
		cout << idx[cur] + 1 << endl;
		res--; last = cur; cur++;
	}
	cin.ignore(2); return 0;
}