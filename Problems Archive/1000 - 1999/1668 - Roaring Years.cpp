#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

string s; string res;

bool compare(const string& a, const string& b) {
	int n = (int)a.size(), m = (int)b.size();
	return n == m ? a < b : n < m;
}

void findNextRoaring(const string s) {
	int n = (int)s.size();
	for (int len = 1; len <= n; len++) {
		string pref = s.substr(0, len);
		for (int i = 0; i < 1000; i++) {
			if (pref.size() > 19) { continue; }
			ll curP = stoll(pref) + i; string cur = "";
			int j = 0; while (compare(cur, s) || cur == s) { j++; cur += to_string(curP++); }
			if (j != 1 && compare(cur, res)) { res = cur; }
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> s; int n = (int)s.size(); res = string(100, '9');
		findNextRoaring(s); findNextRoaring("1" + string(n, '0'));
		cout << "Case #" << t << ": " << res << '\n';
	}
	cin.ignore(2); return 0;
}