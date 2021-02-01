#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> patterns;
vector<string> pref, suf, middle;

bool compare(const string &a, const string &b) { return a.size() < b.size(); }

bool checkPref(const string &a, const string &b) {
	for(int i = 0; i < (int)a.size(); i++)
		if (a[i] != b[i]) { return false; }
	return true;
}

string solve() {
	pref.clear(); suf.clear(); middle.clear();
	for (auto &x : patterns) {
		int n = (int)x.size();
		int i = 0; while (x[i] != '*') { i++; }
		pref.push_back(x.substr(0, i));
		int j = n - 1; while (x[j] != '*') { j--; }
		suf.push_back(x.substr(j + 1, n - j + 1));

		string mid = "";
		for(int k = i; k <=j; k++)
			if (x[k] != '*') { mid.push_back(x[k]); }
		middle.push_back(mid);
	}
	sort(pref.begin(), pref.end(), compare);
	sort(suf.begin(), suf.end(), compare);
	for (auto &x : suf) { reverse(x.begin(), x.end()); }
	for (int i = 1; i < (int)pref.size(); i++)
		if (!checkPref(pref[i - 1], pref[i])) { return "*"; }
	for (int i = 1; i < (int)suf.size(); i++)
		if (!checkPref(suf[i - 1], suf[i])) { return "*"; }

	string res, resPref, resMid = "", resSuf;
	resPref = pref.back(); resSuf = suf.back(); reverse(resSuf.begin(), resSuf.end());
	for (auto &x : middle) { resMid += x; }
	res = resPref + resMid + resSuf; return move(res);
}

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n; patterns.resize(n);
		for (auto &x : patterns) { cin >> x; }
		cout << "Case #" << t << ": " << solve() << '\n';
	}
	cin.ignore(2); return 0;
}