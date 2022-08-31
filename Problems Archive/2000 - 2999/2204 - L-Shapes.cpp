#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> G; int n, m;

int di1[4] = { 1, 1, 0, 0 };
int di2[4] = { 1, 1, 1, 1 };
int dj1[4] = { 0, -1, 1, 1 };
int dj2[4] = { 1, 0, 1, 0 };

int di[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dj[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool checkG(int i, int j, int k) {
	if (i + di1[k] >= n || i + di2[k] >= n) return false;
	if (j + dj1[k] < 0 || j + dj1[k] >= m) return false;
	if (j + dj2[k] < 0 || j + dj2[k] >= m) return false;
	if (G[i + di1[k]][j + dj1[k]] != '*') return false;
	if (G[i + di2[k]][j + dj2[k]] != '*') return false;
	return true;
}

bool checkV(vector<vector<int>> &v, int i, int j, int k) {
	if (i + di[k] < 0 || i + di[k] >= n) return true;
	if (j + dj[k] < 0 || j + dj[k] >= m) return true;
	if (v[i + di[k]][j + dj[k]] == 0) return true;
	return v[i][j] == v[i + di[k]][j + dj[k]];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> m; G.resize(n);
		for (auto& x : G) cin >> x;

		vector<vector<int>> v(n, vector<int>(m, 0));
		int L = 1; bool ok = true;
		
		for(int i = 0; i < n && ok; i++)
			for (int j = 0; j < m; j++) if (!v[i][j] && G[i][j] == '*') {
				for (int k = 0; k < 4; k++) if (checkG(i, j, k)) {
					v[i][j] = v[i + di1[k]][j + dj1[k]] = v[i + di2[k]][j + dj2[k]] = L++; break;
				}
				if (!v[i][j]) { ok = false; break; }
			}
		
		for(int i = 0; i < n && ok; i++)
			for(int j = 0; j < m && ok; j++) if(v[i][j])
				for(int k = 0; k < 8; k++)
					if (!checkV(v, i, j, k)) { ok = false; break; }

		cout << (ok ? "YES" : "NO") << '\n';
	}
}