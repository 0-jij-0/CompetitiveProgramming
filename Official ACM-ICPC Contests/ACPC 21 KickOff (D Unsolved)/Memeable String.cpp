#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> freq;
vector<int> idx;
string s, p, b;

int main() {
	freopen("protecting-memes.in", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m >> s >> p >> b;
		freq.clear(); idx.clear(); 
		freq.resize(26); idx.resize(26);
		for (int i = 0; i < n; i++)
			freq[s[i] - 'a'].push_back(i);

		for (int i = 0; i < 26; i++)
			idx[i] = (int)freq[i].size() - 1;

		vector<int> ans(m, 0);
		int i = n - 1, j = m - 1; while (j != -1) {
			int c = p[j] - 'a';
			while (freq[c][idx[c]] > i) { idx[c]--; }
			ans[j] = freq[c][idx[c]]; j--; i = freq[c][idx[c]] - 1;
		}

		idx.clear(); idx.resize(26, 0);
		string temp(n, '0'); i = 0; j = 0; while (j != m) {
			int c = p[j] - 'a'; while (freq[c][idx[c]] < i) { idx[c]++; }
			while (freq[c][idx[c]] < ans[j] && b[freq[c][idx[c]]] == '1') { idx[c]++; }
			temp[freq[c][idx[c]]] = '1'; j++; i = freq[c][idx[c]] + 1;
		}

		string res(n, '0');	for(int i = 0; i < n; i++)
			if (temp[i] == '0' && b[i] == '1') { res[i] = '1'; }

		cout << res << '\n';
	}

	cin.ignore(2); return 0;
}