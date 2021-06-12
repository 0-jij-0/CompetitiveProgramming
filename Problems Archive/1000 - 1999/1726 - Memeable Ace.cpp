#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> freq;

int main() {
	freopen("max-pair.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s; freq.clear(); freq.resize(26);
		for (int i = 0; i < (int)s.size(); i++)
			freq[s[i] - 'a'].push_back(i);

		int res = 0;
		for (int i = 0; i < 26; i++) if (!freq[i].empty())
			for (int j = i + 1; j < 26; j++) if (!freq[j].empty())
				res = max({ res, freq[i].back() - freq[j].front(), freq[j].back() - freq[i].front() });

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}