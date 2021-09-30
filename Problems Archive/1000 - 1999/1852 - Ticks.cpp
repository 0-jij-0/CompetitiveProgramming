#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
vector<vector<int>> valid;
int n, m, k;

int check(int i, int j) {
	int res = 0, jL = j, jR = j;
	while (i && jL && jR != m - 1 && v[i - 1][jL - 1] == v[i - 1][jR + 1] && v[i - 1][jL - 1] == '*') {
		res++; i--; jL--; jR++;
	}
	return res;
}

void markValid(int i, int j, int d) {
	valid[i][j] = true; int jL = j - 1, jR = j + 1; i--;
	while (d--) { valid[i][jL--] = 1; valid[i--][jR++] = 1; }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> n >> m >> k; v.resize(n); valid.clear(); 
		valid.resize(n, vector<int>(m, 0));
		for (auto& x : v) { cin >> x; }

		for (int i = n - 1; i >= 0; i--)
			for (int j = 0; j < m; j++) if (v[i][j] == '*') {
				int d = check(i, j); 
				if (d < k) { continue; }
				markValid(i, j, d);
			}

		bool ok = true; for(int i = 0; i < n && ok; i++)
			for(int j = 0; j < m; j++) if(v[i][j] == '*')
				if (!valid[i][j]) { ok = false; break; }

		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}