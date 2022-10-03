#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int logN = 18;

vector<pair<int, int>> M;
vector<int> suff;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q; M.resize(n);
	for (auto& [a, b] : M) cin >> a >> b;
	sort(M.begin(), M.end()); suff.resize(n, n - 1);

	for (int i = n - 2; i >= 0; i--)
		suff[i] = (M[i].second < M[suff[i + 1]].second ? i : suff[i + 1]);

	vector<vector<int>> res(logN, vector<int>(n, -1));
	for (int i = 0; i < n - 1; i++) {
		auto it = lower_bound(M.begin(), M.end(), make_pair(M[i].second, -1));
		res[0][i] = it == M.end() ? -1 : suff[it - M.begin()];
	}

	for (int m = 1; m < logN; m++)
		for (int i = 0; i < n; i++) if(res[m - 1][i] != -1)
			res[m][i] = res[m - 1][res[m - 1][i]];

	while (q--) {
		int L, R; cin >> L >> R;
		auto it = lower_bound(M.begin(), M.end(), make_pair(L, -1));
		int cur = it == M.end() ? -1 : suff[it - M.begin()];
		if (cur == -1 || M[cur].second > R) { cout << "0\n"; continue; }

		int ans = 1; for (int m = logN - 1; m >= 0; m--) {
			if (res[m][cur] == -1 || M[res[m][cur]].second > R) { continue; }
			ans += 1 << m; cur = res[m][cur];
		}

		cout << ans << '\n';
	}
}