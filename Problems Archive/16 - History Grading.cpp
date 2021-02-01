#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> correctEvents, myEvents, myOrder;
int dp[21][21], choice[21][21]; int n;

bool compare(const int &i, const int &j) {
	return correctEvents[i] < correctEvents[j];
}

int LIS(int cur, int prev) {
	if (cur == n) { return 0; }
	if (dp[cur][prev] != -1) { return dp[cur][prev]; }

	int a = LIS(cur + 1, prev);
	int b = compare(myEvents[prev], myEvents[cur]) ? 1 + LIS(cur + 1, cur) : 0;

	choice[cur][prev] = (a > b) ? 1 : 2;
	return dp[cur][prev] = max(a, b);
}

void printLIS(int len) {
	int cur = 1, prev = 0;
	while (cur < n) {
		if (1 + dp[cur][prev] == len) { break; }
		cur++; prev++;
	}
	cout << myEvents[prev] + 1 << ' '; len--;
	while (len) {
		if (choice[cur][prev] == 1) { cur++; continue; }
		len--; cout << myEvents[cur]  + 1 << ' '; prev = cur; cur++;
	}
	cout << '\n' << '\n';
}

int main() {
	string s; getline(cin, s);
	while (!s.empty()) {
		n = stoi(s); correctEvents.resize(n); 
		myEvents.resize(n);
		getline(cin, s); stringstream ss(s);
		for (auto &x : correctEvents) { ss >> x; x--; }

		getline(cin, s);
		while (s.find(' ') < s.size()) {
			ss = stringstream(s);
			for (int i = 0; i < n; i++) {
				int x; ss >> x; myEvents[x - 1] = i;
			}
			fill(dp[0], dp[0] + 21 * 21, -1); int res = 0;
			for (int i = 0; i < n - 1; i++)
				res = max(res, 1 + LIS(i + 1, i));
			cout << res << '\n';// << "LIS: "; printLIS(res);
			getline(cin, s);
		}
	}
	cin.ignore(2); return 0;
}