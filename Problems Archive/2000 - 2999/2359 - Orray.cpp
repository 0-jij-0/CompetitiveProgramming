#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n; v.resize(n); 
		vector<int> bits[30];

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			for (int j = 0; j < 30; j++)
				if (v[i] & (1 << j)) bits[j].push_back(i);
		}

		vector<int> vis(n, 0), res; int curOr = 0;
		for (int i = 29; i >= 0; i--) {
			if (bits[i].empty() || (curOr & (1 << i))) continue;
			int ans = bits[i][0]; for (auto& x : bits[i]) if(!vis[x])
				if ((curOr | v[x]) > (curOr | v[ans])) { ans = x; }
			curOr |= v[ans]; vis[ans] = 1; res.push_back(v[ans]);
		}

		for (auto& x : res) cout << x << ' ';
		for (int i = 0; i < n; i++) if (!vis[i]) cout << v[i] << ' '; cout << '\n';
	}
}