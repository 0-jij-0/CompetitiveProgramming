#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> prefixFunction(string& s) {
	vector<int> pf(s.size(), 0);
	for (int i = 1; i < s.size(); i++) {
		int j = pf[i - 1];
		while (j > 0 && s[j] != s[i]) { j = pf[j - 1]; }
		if (s[j] == s[i]) { j++; }
		pf[i] = j;
	}
	return move(pf);
}

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> s; int n = (int)s.size();
	vector<int> pf = prefixFunction(s);
	vector<int> res; int cur = n - 1; 
	while (pf[cur]) res.push_back(cur = (pf[cur] - 1));

	reverse(res.begin(), res.end());
	for (auto& x : res) cout << x + 1 << ' '; cout << '\n';
	cin.ignore(2); return 0;
}