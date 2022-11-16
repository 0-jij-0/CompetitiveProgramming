#include <iostream>
#include <vector>
using namespace std;
const int INF = 1 << 30;

int DP[101][1024], C[10][100];
vector<vector<int>> res;

int main() {
	freopen("mercato.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	for (int i = 0; i < 1024; i++) DP[0][i] = i ? INF : 0;

	int T; cin >> T; while(T--) {
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)	cin >> C[i][j];

		for (int i = 0; i < m; i++)
			for (int mask = 0; mask < (1 << n); mask++) {
				DP[i + 1][mask] = INF; for (int j = 0; j < n; j++)
					DP[i + 1][mask] = min(DP[i + 1][mask], DP[i][mask ^ (1 << j)] + C[j][i]);
			}

		
		int i = m, mask = (1 << n) - 1;
		cout << DP[i][mask] << '\n';
		res.clear(); res.resize(n);

		while (i) {
			for (int j = 0; j < n; j++) 
				if (DP[i][mask] == DP[i - 1][mask ^ (1 << j)] + C[j][i - 1]) {
					res[j].push_back(i); mask ^= (1 << j); --i; break;
				}
		}

		for (auto& x : res) {
			cout << x.size() << ' '; for (auto& y : x)
				cout << y << ' '; cout << '\n';
		}
	}
}