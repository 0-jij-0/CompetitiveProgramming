#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

bool check(string str) {
	if (str.size() % 2) { return true; }
	sort(str.begin(), str.end());
	int idx = lower_bound(str.begin(), str.end(), '1') - str.begin();
	return idx != str.size() / 2;
}

int main() {
	int n; cin >> n >> s;
	if (check(s)) { cout << 1 << endl << s << endl; }
	else { cout << 2 << endl << s.substr(0, s.size() - 1) << ' ' << s.back() << endl; }
	cin.ignore(2); return 0;
}