#include <iostream>
#include <string>
#include <vector>
using namespace std;

int freq[2];
string s, t;
vector<pair<int, int>> res;

int main() {
	int n; cin >> n >> s >> t;
	freq[0] = freq[1] = 0;
	for (auto &c : s) { freq[c - 'a']++; }
	for (auto &c : t) { freq[c - 'a']++; }
	if (freq[0] % 2) { cout << -1 << endl; }
	else {
		vector<int> ab, ba;
		for (int i = 0; i < n; i++) {
			if (s[i] == t[i]) { continue; }
			if (s[i] == 'a') { ab.push_back(i); }
			else { ba.push_back(i); }
		}
		while (ab.size() > 1) {
			int x = ab.back(); ab.pop_back();
			int y = ab.back(); ab.pop_back();
			res.push_back({ x + 1, y + 1 });
		}
		while (ba.size() > 1) {
			int x = ba.back(); ba.pop_back();
			int y = ba.back(); ba.pop_back();
			res.push_back({ x + 1 , y + 1 });
		}
		if (!ab.empty()) { 
			res.push_back({ ab.back() + 1, ab.back() + 1 });
			res.push_back({ ab.back() + 1, ba.back() + 1 });
		}
		cout << res.size() << endl;
		for (auto &x : res) { cout << x.first << ' ' << x.second << endl; }
	}
	cin.ignore(2); return 0;
}