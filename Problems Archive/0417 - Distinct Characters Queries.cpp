#include <iostream>
#include <string>
#include <set>
using namespace std;

set<int> idx[26];
string s;

int main() {
	int q; cin >> s >> q;
	for (int i = 0; i < (int)s.size(); i++)
		idx[s[i] - 'a'].insert(i);
	while (q--) {
		int t; cin >> t;
		if(t == 1) {
			int id; char c; cin >> id >> c;
			id--; idx[s[id] - 'a'].erase(id);
			idx[c - 'a'].insert(id); s[id] = c;
		}
		else {
			int l, r; cin >> l >> r; 
			l--; r--; int res = 0;
			for (int j = 0; j < 26; j++) {
				auto a = idx[j].lower_bound(l);
				if (a == idx[j].end()) { continue; }
				res += (*a <= r);
			}
			cout << res << endl;
		}
	}
	cin.ignore(2); return 0;
}