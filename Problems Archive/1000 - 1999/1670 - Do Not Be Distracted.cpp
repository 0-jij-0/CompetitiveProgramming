#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; string s; cin >> n >> s; 
		set<char> st; st.insert(s[0]); bool ok = true;
		for (int i = 1; i < n; i++) {
			if (s[i] == s[i - 1]) { continue; }
			if (st.count(s[i])) { ok = false; break; }
			st.insert(s[i]);
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}