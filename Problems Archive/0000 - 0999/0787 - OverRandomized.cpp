#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long ll;

int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int u; cin >> u; 
		map<char, int> m; set<char> s;
		for (int i = 0; i < 10000; i++) {
			ll q; string str; cin >> q >> str; 
			m[str[0]]++; for (char &c : str) { s.insert(c); }
		}
		for (const char &c : s) { m[c]++; m[c]--; }
		vector<pair<int, char>> v;
		for (auto &x : m) { v.push_back({ x.second, x.first }); }
		sort(v.rbegin(), v.rend());
		pair<int, char> p = v.back();
		v.pop_back(); v.insert(v.begin(), p);
		cout << "Case #" << t << ": ";
		for (auto &x : v) { cout << x.second; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}