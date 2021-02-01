#include <iostream>
#include <string>
#include <set>
using namespace std;

string s, t;

bool check() {
	set<int> st;
	for (auto &c : s) { st.insert(c); }
	for (auto &c : t) if (st.count(c)) { return true; }
	return false;
}

int main() {
	int q; cin >> q;
	while (q--) {
		cin >> s >> t;
		bool b = check();
		cout << (b ? "YES" : "NO") << endl;
	}
	cin.ignore(2); return 0;
}