#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
struct quest {
	int xp1, xp2;
	ll t1, t2;
	
	quest(int _xp1, ll _t1, int _xp2, ll _t2) :xp1(_xp1), xp2(_xp2), t1(_t1), t2(_t2) {}
 
	bool operator<(quest &rhs) {
		return xp1 < rhs.xp1;
	}
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n, s1, s2; cin >> n >> s1 >> s2;
	vector<quest> quests;
	for (int i = 0; i < n; i++) {
		ll x, t, y, r; cin >> x >> t >> y >> r;
		quest qq(x, t, y, r);
		quests.push_back(qq);
	}
	sort(quests.begin(), quests.end());
 
	vector<vector<ll>> dp(s1+1, vector<ll>(s2+1, (ll)1e14));
	//dp[i][j] = min time needed to get i xp in lvl 1 and j xp in lvl 2
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = s1; j >= 0; j--) {
			for (int k = s2; k >= 0; k--) {
				int nextLv1 = 0, over = 0, nxtLv2 = k;
				if (j < s1) {
					if (j + quests[i].xp1 >= s1) {
						nextLv1 = s1;
						over = j + quests[i].xp1 - s1;
						nxtLv2 += over; nxtLv2 = min(nxtLv2, s2);
					}
					else { nextLv1 = j + quests[i].xp1; }
 
					dp[nextLv1][nxtLv2] = min(dp[nextLv1][nxtLv2], dp[j][k] + quests[i].t1);
				}
 
				nxtLv2 = k + quests[i].xp2; nxtLv2 = min(nxtLv2, s2);
				dp[j][nxtLv2] = min(dp[j][nxtLv2], dp[j][k] + quests[i].t2);
			}
		}
	}
 
	cout << (dp[s1][s2] == (ll)1e14 ? -1 : dp[s1][s2]) << endl;
}