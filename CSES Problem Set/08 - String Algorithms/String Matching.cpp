#include <bits/stdc++.h>
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

int stringMatch(string& t, string& s) {
	string temp = s + '#' + t;
	vector<int> pf = prefixFunction(temp);
	return count(pf.begin() + s.size() + 1, pf.end(), s.size());
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s, p; cin >> s >> p;
	cout << stringMatch(s, p) << '\n';
}