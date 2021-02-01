#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
typedef long long ll;

vector<int> a, b, v[2];

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; v[0].clear();
		a.resize(n); b.resize(n); v[1].clear();
		for (auto& x : a) { cin >> x; }
		for (auto& x : b) { cin >> x; }
		for (int i = 0; i < n; i++) v[b[i] - 1].push_back(a[i]);

		sort(v[0].rbegin(), v[0].rend());
		sort(v[1].rbegin(), v[1].rend());

		
		int j = (int)v[1].size() - 1;
		ll loss = accumulate(v[1].begin(), v[1].end(), 0ll);
		int cur = 2 * (j + 1), res = 1 << 20;
		while (j > 0 && loss - m >= v[1][j]) { loss -= v[1][j--]; cur -= 2; }
		if (loss >= m) { res = cur; }


		for (int i = 0; i < (int)v[0].size(); i++) {
			cur++; loss += v[0][i]; if (loss < m) { continue; }
			while (j >= 0 && loss - m >= v[1][j]) { cur -= 2; loss -= v[1][j--]; }
			res = min(res, cur);
		}
		cout << (res > cur ? -1 : res) << '\n';
	}
	cin.ignore(2); return 0;
}