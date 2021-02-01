#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<int> par[22];
map<int, vector<int>> eqClass;
vector<int> color;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m; 
		color.resize(n*m); eqClass.clear();
		for (auto &x : par) { x.resize(n*m); }
		for (int i = 0; i < n*m; i++) {
			char c; cin >> c; color[i] = c - '0';
		}
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int idx = i * m + j; char c; cin >> c;
				if (c == 'U') { par[0][idx] = (i - 1)*m + j; continue; }
				if (c == 'D') { par[0][idx] = (i + 1)*m + j; continue; }
				if (c == 'L') { par[0][idx] = i * m + j - 1; continue; }
				if (c == 'R') { par[0][idx] = i * m + j + 1; continue; }
			}
		for (int step = 1; step < 22; step++)
			for (int i = 0; i < n*m; i++)
				par[step][i] = par[step - 1][par[step - 1][i]];

		for (int i = 0; i < n*m; i++) { eqClass[par[21][i]].push_back(i); }
		int total = (int) eqClass.size(), black = 0;
		for (auto &x : eqClass) for (auto &y : x.second) if (!color[y]) { black++; break; }
		cout << total << ' ' << black << '\n';
	}
	cin.ignore(2); return 0;
}