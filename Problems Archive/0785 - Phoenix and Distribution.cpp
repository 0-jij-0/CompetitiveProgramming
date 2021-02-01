#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, k; string s; cin >> n >> k >> s;
		sort(s.begin(), s.end());
		if (s[0] != s[k - 1]) { cout << s[k - 1] << endl; continue; }
		if (s[k] != s[n - 1]) { cout << s.substr(k - 1) << endl; continue; }
		int count = (n - 1) / k;
		cout << string(1, s[0]) + string(count, s[k]) << endl;
	}
	cin.ignore(2); return 0;
}