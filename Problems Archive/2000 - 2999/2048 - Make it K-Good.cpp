#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

string s;

int main() {
	freopen("good.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, k; cin >> n >> k >> s;
		vector<vector<int>> v(k, vector<int>(26, 0));
		for (int i = 0; i < n; i++) v[i % k][s[i] - 'a']++;

		int res = 0; for (auto& x : v) {
			int all = accumulate(x.begin(), x.end(), 0);
			int ma = *max_element(x.begin(), x.end());
			res += all - ma;
		}

		cout << res << '\n';
	}
}