#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> s; int n = (int)s.size(); 
		int m = (int)set<char>(s.begin(), s.end()).size();

		vector<int> res; set<char> vis;
		for (int i = 0; i < m; i++) {
			vector<int> freq(26, 0);
			int j = res.empty() ? 0 : res.back() + 1;
			while (j != n) { if (!vis.count(s[j])) freq[s[j] - 'a']++; j++; }

			j = res.empty() ? 0 : res.back() + 1; int ans = -1;
			for (; j < n; j++) if (!vis.count(s[j])) {
				if (ans == -1 || s[j] > s[ans]) { ans = j; }
				if (freq[s[j] - 'a'] == 1) break; freq[s[j] - 'a']--;
			}
			res.push_back(ans); vis.insert(s[ans]);
		}

		for (auto& x : res) cout << s[x]; cout << '\n';
	}
	cin.ignore(2); return 0;
}