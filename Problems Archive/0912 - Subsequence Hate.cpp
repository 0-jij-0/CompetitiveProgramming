#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;	int z = 0, o = 0;
		for (char &c : s) { (c == '0' ? z : o)++; }
		int res = o, cz = 0, co = 0, n = (int)s.size();
		for (int i = 0; i < n; i++) {
			cz += (s[i] == '0'); z -= (s[i] == '0');
			co += (s[i] == '1'); o -= (s[i] == '1');
			res = min({ res, cz + o, co + z });
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}