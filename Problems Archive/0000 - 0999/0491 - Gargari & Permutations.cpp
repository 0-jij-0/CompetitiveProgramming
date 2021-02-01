#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> v;
vector<int> lp;
int n, k;

int longest_path(int u) {
	if (lp[u] != -1) { return lp[u]; }
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (!adj[u][i] || i == u) { continue; }
		res = max(res, longest_path(i));
	}
	return lp[u] = 1 + res;
}

int main() {
	cin >> n >> k;
	adj.resize(n, vector<int>(n, 1));
	v.resize(k, vector<int>(n));
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++) {
			cin >> v[i][j]; v[i][j]--;
		}
	for (int i = 0; i < k; i++)
		for (int j = n - 1; j >= 0; j--)
			for (int l = j - 1; l >= 0; l--)
				adj[v[i][j]][v[i][l]] = 0;
	int res = 0; lp.resize(n, -1);
	for (int i = 0; i < n; i++) {
		res = max(res, longest_path(i));
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}