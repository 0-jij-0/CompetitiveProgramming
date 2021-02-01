#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; string s; cin >> n >> s;
		string res = ""; bool one = false;
		int j = n - 1; while (j >= 0 && s[j] == '1') { res.push_back(s[j--]); }
		if (j >= 0) { res.push_back('0'); }
		int i = 0; while (i < j && s[i] == '0') { res.push_back(s[i++]); }
		reverse(res.begin(), res.end()); cout << res << '\n';
	}
	cin.ignore(2); return  0;
}