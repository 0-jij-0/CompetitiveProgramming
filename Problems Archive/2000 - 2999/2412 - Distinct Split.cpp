#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t; cin >> t; while (t--) {
		int n; cin >> n >> s;
		int B = (int) set<char>(s.begin(), s.end()).size();
		vector<int> first(26, -1), last(26);
		for (int i = 0; i < n; i++) {
			if (first[s[i] - 'a'] == -1) first[s[i] - 'a'] = i;
			last[s[i] - 'a'] = i;
		}
		vector<int> add, sub;
		for (int i = 0; i < 26; i++) if (first[i] != -1) {
			add.push_back(first[i]); sub.push_back(last[i]);
		}
		sort(add.begin(), add.end());
		sort(sub.begin(), sub.end());

		int i = 0, j = 0, A = 0, res = 0, M = (int)add.size();
		for (int k = 0; k < n; k++) {
			if (i < M && add[i] == k) { A++; i++; }
			if (j < M && sub[j] == k) { B--; j++; }
			res = max(res, A + B);
		}

		cout << res << '\n';
	}
}