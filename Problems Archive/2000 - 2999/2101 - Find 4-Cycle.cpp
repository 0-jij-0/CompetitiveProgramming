#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> G, F;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int s, t, m; cin >> s >> t >> m;
	G.resize(s); F.resize(t, vector<int>(t, -1));
	
	while (m--) {
		int u, v; cin >> u >> v;
		G[--u].push_back(--v - s);
	}

	bool ok = false;
	for (int i = 0; i < s && !ok; i++) {
		int E = (int)G[i].size();
		for(int j = 0; j < E - 1 && !ok; j++)
			for(int k = j + 1; k < E; k++)
				if (F[G[i][j]][G[i][k]] != -1) {
					cout << F[G[i][j]][G[i][k]] + 1 << ' ' << i + 1 << ' ';
					cout << G[i][j] + s + 1 << ' ' << G[i][k] + s + 1 << '\n';
					ok = true; break;
				}
				else { F[G[i][j]][G[i][k]] = F[G[i][k]][G[i][j]] = i; }
	}

	if (!ok) { cout << -1 << '\n'; }
}