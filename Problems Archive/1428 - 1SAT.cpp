#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, pair<int, int>> m;

int main() {
	int n; cin >> n; while (n--) {
		string s; cin >> s;
		if (s[0] != '!' && !m.count(s)) { m[s] = { 1, 0 }; continue; }
		if (s[0] != '!') { m[s].first = 1; continue; }
		s.erase(s.begin());
		if (m.count(s)) { m[s].second = 1; continue; }
		m[s] = { 0, 1 };
	}

	bool ok = false; for(auto &x : m)
		if (x.second.first && x.second.second) {
			ok = true; cout << x.first << '\n'; break;
		}
	if (!ok) { cout << "satisfiable" << '\n'; }
	cin.ignore(2); return 0;
}