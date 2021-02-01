#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool isPal(const string &s) {
	int i = 0, j = (int)s.size() - 1;
	while (i < j) if (s[i++] != s[j--]) { return false; }
	return true;
}

set<string> pal, queue, used;
vector<string> v;

int main() {
	int n, m; cin >> n >> m; 
	v.resize(n); pal.insert("");
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < n; i++) {
		string s = v[i]; reverse(s.begin(), s.end());
		if (queue.count(s)) { used.insert(s); queue.erase(s); continue; }
		if (isPal(v[i])) { pal.insert(v[i]); continue; }
		queue.insert(v[i]);
	}
	string f, l; 
	for (auto &x : used) { f += x; }
	l = f; reverse(l.begin(), l.end());
	string res = f + *pal.rbegin() + l;
	cout << res.size() << endl << res << endl;
	cin.ignore(2); return 0;
}