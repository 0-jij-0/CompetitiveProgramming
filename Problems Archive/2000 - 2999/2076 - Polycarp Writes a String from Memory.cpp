#include <iostream>
#include <string>
#include <set>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		cin >> s; int n = (int)s.size();

		int i = 0, j = 0, res = 0;
		set<char> st; while (i != n && ++res) {
			while (j != n && (st.size() < 3 || st.count(s[j]))) { st.insert(s[j++]); }
			i = j; st.clear();
		}
		cout << res << '\n';
	}
}