#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string s; cin >> s; int n = (int)s.size();
		map<char, int> m; for (char& c : s) m[c]++;

		char mi = m.begin()->first;	for (auto& c : m) 
			if (m[mi] > m[c.first]) { mi = c.first; }

		if (m[mi] == 1) {
			cout << mi; m.erase(mi);
			for (auto& x : m) cout << string(x.second, x.first);
		}
		else if (m.size() == 1) { cout << s; }
		else {
			auto it = m.begin();
			int overlap = it->second - 2;
			if (overlap <= n - it->second) {
				string other = "";
				for (auto itt = ++m.begin(); itt != m.end(); itt++)
					other += string(itt->second, itt->first);

				cout << string(2, it->first); string first = string(overlap, it->first);
				int i = 0, j = 0; while (i != first.size() && j != other.size()) {
					cout << other[j++] << first[i++];
				} while (j != other.size()) { cout << other[j++]; }
			}
			else if(m.size() == 2) {
				for (int i = 0; i < 2; i++, it++) {
					cout << it->first; it->second--;
				}
				string last = string(m.begin()->second, m.begin()->first);
				m.erase(m.begin()); for (auto& x : m) cout << string(x.second, x.first);
				cout << last;
			}
			else {
				for (int i = 0; i < 2; i++, it++) {
					cout << it->first; it->second--;
				}
				string last = string(m.begin()->second, m.begin()->first);
				cout << last; m.erase(m.begin());
				auto it = ++m.begin(); cout << it->first; it->second--;
				for (auto& x : m) cout << string(x.second, x.first);
			}
		}
		cout << '\n'; 
	}
	cin.ignore(2); return 0;
}