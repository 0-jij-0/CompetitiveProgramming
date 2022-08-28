#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		string a, b; cin >> a >> b;
		string s = a + b; sort(s.begin(), s.end());
		if (s[0] == s[3]) { cout << "0\n"; continue; }
		if (s[0] == s[2] || s[1] == s[3]) { cout << "1\n"; continue; }
		if (s[0] == s[1] && s[2] == s[3]) { cout << "1\n"; continue; }
		if (s[0] == s[1] || s[1] == s[2] || s[2] == s[3]) { cout << "2\n"; continue; }
		cout << 3 << '\n';
	}
}