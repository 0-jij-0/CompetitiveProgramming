#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n);
		for (auto& x : v) cin >> x;

		vector<vector<int>> nodes(n + 1);

		for (int i = 0; i < n; i++) 
			if (i + 1 + v[i] <= n) { 
				nodes[i + 1 + v[i]].push_back(i + 1);
			}

		vector<int> DP(n + 1, false);
		for (int i = 0; i <= n; i++)
			if (!i || v[i - 1] == i - 1) DP[i] = true;

		for (int i = 1; i <= n; i++) if(!DP[i]) {
			if (i - v[i - 1] - 1 >= 0 && DP[i - v[i - 1] - 1]) { DP[i] = true; continue; }
			for (auto& e : nodes[i]) if (DP[e - 1]) { DP[i] = true; break; }
		}

		cout << (DP[n] ? "YES" : "NO") << '\n';
	}
}