#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		sort(s.begin(), s.end());
		char c = s[0]; int j = 0;
		for (; j < (int)s.size(); j++) {
			if (s[j] != c + j) { break; }
		}
		if (j == (int)s.size()) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}