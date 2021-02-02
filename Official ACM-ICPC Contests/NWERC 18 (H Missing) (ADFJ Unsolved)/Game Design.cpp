#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<pair<int, int>> v;

bool check(char a, char b) {
	if (a == 'L' && b == 'R') { return true; }
	if (a == 'R' && b == 'L') { return true; }
	if (a == 'U' && b == 'D') { return true; }
	if (a == 'D' && b == 'U') { return true; }
	return false;
}

int main() {
	string s; cin >> s; int n = (int)s.size();
	int px = 0, x = 0, py = 0, y = 0; bool ok = true;
	for (int i = 0; i < n; i++) {
		if (i && i == n - 1 && check(s[i], s[i - 1])) { 
			if (s[i] == 'L' && v.count({ px - 1, py })) { ok = false; break; }
			if (s[i] == 'R' && v.count({ px + 1, py })) { ok = false; break; }
			if (s[i] == 'U' && v.count({ px, py + 1 })) { ok = false; break; }
			if (s[i] == 'D' && v.count({ px, py - 1 })) { ok = false; break; }
		}
		else if (i && check(s[i], s[i - 1])) { 
			if (s[i] == 'L' && v.count({ px - 1, py })) { swap(px, x); swap(py, y); continue; }
			if (s[i] == 'R' && v.count({ px + 1, py })) { swap(px, x); swap(py, y); continue; }
			if (s[i] == 'U' && v.count({ px, py + 1 })) { swap(px, x); swap(py, y); continue; }
			if (s[i] == 'D' && v.count({ px, py - 1 })) { swap(px, x); swap(py, y); continue; }
		}
		if (s[i] == 'L') { px = x; py = y; x -= 1 << i; v.insert({ x - 1, y }); continue; }
		if (s[i] == 'R') { px = x; py = y; x += 1 << i; v.insert({ x + 1, y }); continue; }
		if (s[i] == 'U') { px = x; py = y; y += 1 << i; v.insert({ x, y + 1 }); continue; }
		if (s[i] == 'D') { px = x; py = y; y -= 1 << i; v.insert({ x, y - 1 }); continue; }
	}
	if (!ok) { cout << "impossible" << '\n'; return 0; }
	cout << -x << ' ' << -y << '\n' << v.size() << '\n';
	for (auto &p : v) { cout << p.first - x << ' ' << p.second  - y << '\n'; }
	cin.ignore(2); return 0;
}