#include <iostream>
#include <string>
#include <set>
using namespace std;

string s;
set<int> idx[26];

string query(int l, int r) {
	if (l == r || s[l] != s[r]) { return "Yes"; }
	int num = 0;
	for (int i = 0; i < 26; i++) {
		auto a = idx[i].lower_bound(l);
		if (a == idx[i].end()) { continue; }
		num += (*a <= r);
	}
	return num < 3 ? "No" : "Yes";
}

int main() {
	int q; cin >> s >> q;
	for (int i = 0; i < (int)s.size(); i++)
		idx[s[i] - 'a'].insert(i);
	while (q--) {
		int l, r; cin >> l >> r; l--; r--;
		cout << query(l, r) << endl;
	}
	cin.ignore(2); return 0;
}