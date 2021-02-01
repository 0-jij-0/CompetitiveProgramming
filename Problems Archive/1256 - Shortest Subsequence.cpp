#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s; int n = (int)s.size();
	string res = ""; int i = 0; bool ok = true;
	
	while (i < n) {
		set<char> st = { 'A', 'C', 'G', 'T' };
		while (i < n && st.size() > 1)
			if (!st.count(s[i])) { i++; }
			else { st.erase(s[i]); i++; }
		if (st.size() == 1) {
			res.push_back(*st.begin());
			while (i < n && s[i] != *st.begin()) { i++; }
			if (i != n) { i++; continue; }
			ok = false; break;
		}
		else { res.push_back(*st.begin()); ok = false; break; }
	}
	if (ok) { res.push_back('A'); }
	cout << res << '\n'; cin.ignore(2); return 0;
}