#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s; 
	int n = (int)s.size();
	string res = "";
	for (int i = 0; i < n - 1; i++) {
		if ((s[i] - '0') % 2 || s[i] > s.back()) { continue; }
		swap(s[i], s[n - 1]); res = s; break;
	}
	if (res != "") { cout << res << endl; return 0; }
	for (int i = n - 1; i >= 0; i--) {
		if ((s[i] - '0') % 2) { continue; }
		swap(s[i], s[n - 1]); res = s; break;
	}
	if (res != "") { cout << res << endl; return 0; }
	cout << -1 << endl;
	cin.ignore(2); return 0;
}