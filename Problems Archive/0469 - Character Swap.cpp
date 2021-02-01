#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s, t;
int freq[26];
vector<pair<int, int>> res;

int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n; s.resize(n); t.resize(n);
		for (int i = 0; i < 26; i++) { freq[i] = 0; }
		for (char &c : s) { cin >> c; }
		for (char &c : t) { cin >> c; }
		res.clear(); int i = 0;
		for (auto &c : s) { freq[c - 'a']++; }
		for (auto &c : t) { freq[c - 'a']++; }
		for (; i < 26; i++)
			if (freq[i] % 2) { cout << "NO" << endl; break; }
		if (i != 26) { continue; }
		cout << "YES" << endl; i = 0;
		while (i != n) {
			if (s[i] == t[i]) { i++; continue; }
			int idx = find(s.begin() + i + 1, s.end(), s[i]) - s.begin();
			if (idx != n) {
				res.push_back({ idx + 1, i + 1 });
				swap(s[idx], t[i]); i++; continue;
			}
			idx = find(t.begin() + i + 1, t.end(), s[i]) - t.begin();
			res.push_back({ n, idx + 1 });
			swap(s[n - 1], t[idx]);
			res.push_back({ n, i + 1 });
			swap(s[n - 1], t[i]); i++;
		}
		cout << res.size() << endl;
		for (auto &x : res) { cout << x.first << ' ' << x.second << endl; }
	}
	cin.ignore(2); return 0;
}