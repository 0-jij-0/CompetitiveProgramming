#include <iostream>
#include <list>
#include <string>
using namespace std;

list<int> res; string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n >> s;
	res.push_back(0); auto last = res.begin();

	int i = 1; for (char& c : s) {
		if (c == 'L') { res.insert(last, i++); --last; continue; }
		if (++last == res.end()) { res.push_back(i++); last = --res.end(); }
		else { res.insert(last, i++); --last; }
	}

	for (auto& x : res) cout << x << ' '; cout << '\n';
	cin.ignore(2); return 0;
}