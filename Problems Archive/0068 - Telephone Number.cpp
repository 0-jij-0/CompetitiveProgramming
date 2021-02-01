#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string number;

bool check(string &s) {
	if (s.size() < 11) { return false; }
	string::iterator it = find(s.begin(), s.end(), '8');
	if (it == s.end()) { return false; }
	int idx = it - s.begin();
	if (s.size() - idx < 11) { return false; }
	return true;
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n >> number;
		if (check(number)) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
	return 0;
}