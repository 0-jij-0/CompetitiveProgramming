#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string subtract(string a, string b) {
	if (a == b) { return "0"; }
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	while (a.size() < b.size()) { a.push_back('0'); }
	while (b.size() < a.size()) { b.push_back('0'); }

	int n = (int)a.size(), carry = 0; string res;
	for (int i = 0; i < n; i++) {
		int x = (a[i] - '0') - (b[i] - '0') - carry;
		if (x >= 0) { res.push_back(x + '0'); carry = 0; }
		else { res.push_back(x + 10 + '0'); carry = 1; }
	}
	while (res.back() == '0') { res.pop_back(); }
	reverse(res.begin(), res.end());
	return move(res);
}

bool compareStrings(const string &a, const string &b) {
	if (a.size() != b.size()) { return a.size() < b.size(); }
	return a < b;
}

bool compare(const pair<string, string> &p1, const pair<string, string> &p2) {
	return compareStrings(p1.first, p2.first);
}

vector<pair<string, string>> v;

int main() {
	int n; string s; cin >> n >> s; v.resize(n);
	for (auto &x : v) { cin >> x.second >> x.first; }
	sort(v.begin(), v.end(), compare);

	int i = n - 1; vector<string> res;
	while (i != -1) {
		if (compareStrings(s, v[i].first)) { i--; continue; }
		s = subtract(s, v[i].first); res.push_back(v[i].second); i--;
	}

	if (s != "0") { res.clear(); }
	cout << res.size() << endl;
	for (auto &x : res) { cout << x << endl; }
	cin.ignore(2); return 0;
}