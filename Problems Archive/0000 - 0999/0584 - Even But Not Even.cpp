#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sum_dig(string &s) {
	int res = 0;
	for (char &c : s) { res += c - '0'; }
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		int ds = sum_dig(s);
		while (!s.empty() && s.back() % 2 == 0) { 
			ds -= s.back() - '0'; s.pop_back();
		}
		if (s.empty()) { cout << -1 << endl; continue; }
		if (ds % 2 == 0) { cout << s << endl; continue; }
		n = (int) s.size();
		for (int i = n - 2; i >= 0; i--) {
			if ((s[i] - '0') % 2) { 
				s.erase(s.begin() + i);
				if (i == 0) {
					reverse(s.begin(), s.end());
					while (!s.empty() && s.back() == '0') { s.pop_back(); }
					reverse(s.begin(), s.end());
				}
				break;
			}
		}
		if (s.empty() || (int) s.size() == n) { cout << -1 << endl; continue; }
		cout << s << endl; continue;
	}
	cin.ignore(2); return 0;
}