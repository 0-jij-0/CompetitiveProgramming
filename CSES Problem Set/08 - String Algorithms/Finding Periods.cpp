#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> prefixFunction(string& s) {
	vector<int> pf(s.size(), 0);
	for (int i = 1; i < (int)s.size(); i++) {
		int j = pf[i - 1];
		while (j > 0 && s[j] != s[i]) { j = pf[j - 1]; }
		if (s[j] == s[i]) { j++; }
		pf[i] = j;
	}
	return move(pf);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s; int n = s.size();
	vector<int> pref = prefixFunction(s);

	vector<int> res; int k = n - 1;
	while (k >= 0) { res.push_back(pref[k]); k = pref[k] - 1; }

	for (auto& x : res)  cout << n - x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}