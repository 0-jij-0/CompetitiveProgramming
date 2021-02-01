#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, string> lang;
vector<string> lect;

string min(const string &a, const string &b) {
	if (a.size() > b.size()) { return move(b); }
	return move(a);
}

int main() {
	int n, m; cin >> n >> m; lect.resize(n);
	for (int i = 0; i < m; i++) {
		string a, b; cin >> a >> b; lang[a] = b;
	}
	for (auto &x : lect) {
		cin >> x; auto it = lang.find(x);
		x = min(it->first, it->second);
	}
	for (auto &x : lect) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}