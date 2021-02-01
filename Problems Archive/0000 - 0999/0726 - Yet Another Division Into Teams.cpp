#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[200005]; int choice[200005];
vector<pair<int, int>> v;
vector<int> ans;
const ll inf = 1ll << 40;

ll diversity(int i) {
	if (i < 0) { return 0; }
	if (i < 2) { return inf; }
	if (dp[i] != -1) { return dp[i]; }

	ll three = v[i].first - v[i - 2].first + diversity(i - 3);
	ll four = (i < 3) ? inf : v[i].first - v[i - 3].first + diversity(i - 4);
	ll five = (i < 4) ? inf : v[i].first - v[i - 4].first + diversity(i - 5);

	if (three <= min(four, five)) { choice[i] = 3; return dp[i] = three; }
	if (four <= min(three, five)) { choice[i] = 4; return dp[i] = four; }
	if (five <= min(four, three)) { choice[i] = 5; return dp[i] = five; }
	return inf;
}

int main() {
	int n; cin >> n; v.resize(n); ans.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first; v[i].second = i;
	}
	sort(v.begin(), v.end());
	memset(dp, -1ll, sizeof(dp));
	memset(choice, -1, sizeof(choice));
	ll res = diversity(n - 1); int team = 1, i = n - 1;
	while (i >= 0) {
		for (int j = 0; j < choice[i]; j++) { ans[v[i - j].second] = team; }
		i -= choice[i]; team++;
	}
	cout << res << ' ' << team - 1 << endl;
	for (auto &x : ans) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}