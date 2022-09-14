#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s; int n = (int)s.size();

		set<int> idx[26]; vector<int> res;
		for (int i = 0; i < n; i++) idx[s[i] - 'a'].insert(i);

		int mi = (s[0] < s[n - 1] ? s[0] : s[n - 1]);
		int ma = (s[0] < s[n - 1] ? s[n - 1] : s[0]);

		for (int i = mi - 'a'; i <= ma - 'a'; i++)
			res.insert(res.end(), idx[i].begin(), idx[i].end());

		if (res[0]) { 
			reverse(res.begin(), res.end()); int m = (int)res.size();
			int i = find(res.begin(), res.end(), 0) - res.begin();
			int j = find(res.begin(), res.end(), n - 1) - res.begin();
			swap(res[0], res[i]); swap(res[m - 1], res[j]);
		}

		cout << ma - mi << ' ' << res.size() << '\n';
		for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	}
}