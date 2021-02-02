#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;
 
vector<int> h; int k, n;
string want, day;
 
int main() {
	cin >> k >> n; h.resize(26);
	for (auto &x : h) { cin >> x; }
	cin >> want >> day;
 
	vector<vector<ll>> dp(2, vector<ll>(n, 0));
	for (int j = n - 1; j >= 0; j--) {
		dp[0][j] = (j < n - 1 ? dp[0][j + 1] : 0);
		dp[0][j] += day[j] == want[k - 1];
	}
 
	bool alt = 1;
	for (int i = k - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			dp[alt][j] = (j < n - 1 ? dp[alt][j + 1] : 0);
			dp[alt][j] %= mod;
			if (day[j] == want[i]) {
				int nextDay = j + 1 + h[day[j] - 'A'];
				if (nextDay < n) { dp[alt][j] += dp[!alt][nextDay]; }
				else { dp[alt][j] = 0; }
				dp[alt][j] %= mod;
			}
		}
		alt = !alt;
	}
 
	cout << dp[!alt][0] << endl;
}