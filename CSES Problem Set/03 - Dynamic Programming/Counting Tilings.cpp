#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

vector<vector<int>> states;
ll dp[2][1 << 10];

void generateStates(int i, int n, vector<int>& curStates) {
	if (i == n) { states.push_back(curStates); return; }

	if (i < n - 1) { 
		curStates.push_back(3); curStates.push_back(4);
		generateStates(i + 2, n, curStates);
		curStates.pop_back(); curStates.pop_back();
	}

	for (int k = 1; k <= 2; k++) {
		curStates.push_back(k);
		generateStates(i + 1, n, curStates);
		curStates.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;	
	vector<int> tmp; generateStates(0, n, tmp);
	vector<pair<int, int>> bitStates;

	for (auto& v : states) {
		int curS = 0, prevS = 0; bool noTwo = true;
		for (int x = 0; x < n; x++) {
			if (v[x] == 1) { curS |= (1 << x); }
			if (v[x] == 2) { prevS |= (1 << x); noTwo = false; }
		}
		bitStates.push_back({ curS, prevS });
		if (noTwo) { dp[0][curS]++; }
	}

	for (int i = 1; i < m; i++) {
		fill(dp[i & 1], dp[i & 1] + (1 << n), 0ll);	for (auto& p : bitStates)
			dp[i & 1][p.first] = (dp[i & 1][p.first] + dp[(i & 1) ^ 1][p.second]) % mod;
	}

	cout << dp[(m & 1) ^ 1][0] << '\n';
}
