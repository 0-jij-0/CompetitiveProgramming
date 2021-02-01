#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n >> s;
		int res = 0, i = 0;
		while (i < n && s[i] != 'A') { i++; }
		while (i < n) {
			while (i < n && s[i] == 'A') { i++; }
			int cur = 0;
			while (i < n && s[i] != 'A') { cur++; i++; }
			res = max(res, cur);
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}