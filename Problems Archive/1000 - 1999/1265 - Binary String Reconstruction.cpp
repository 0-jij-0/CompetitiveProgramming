#include <iostream>
#include <string>
using namespace std;

string s; int n, x;

int main() {
	int t; cin >> t; while (t--) {
		cin >> s >> x; n = (int)s.size();
		string res(n, '1');
		for (int i = 0; i < n; i++) if (s[i] == '0') {
			if (i - x >= 0) { res[i - x] = '0'; }
			if (i + x < n) { res[i + x] = '0'; }
		}
		string S(n, '0');
		for (int i = 0; i < n; i++) {
			if (i - x >= 0 && res[i - x] == '1') { S[i] = '1'; continue; }
			if (i + x < n && res[i + x] == '1') { S[i] = '1'; continue; }
		}
		cout << (s == S ? res : "-1") << '\n';
	}
	cin.ignore(2); return 0;
}