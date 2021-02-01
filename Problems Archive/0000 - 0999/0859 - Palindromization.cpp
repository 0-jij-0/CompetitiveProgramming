#include <iostream>
#include <string>
using namespace std;

bool isPal(string &s, int i, int j) {
	while (i < j) if (s[i++] != s[j--]) return false;
	return true;
}

int makePal(string &s) {
	int i = 0, j = (int)s.size() - 1;
	while (i < j) {
		if (s[i] == s[j]) { i++; j--; continue; }
		if (isPal(s, i + 1, j)) { return i; }
		if (isPal(s, i, j - 1)) { return j; }
		return -1;
	}
	int mid = (int)s.size() / 2; return mid;
}

int main() {
	string s; cin >> s;	int idx = makePal(s);
	if (idx < 0) { cout << "NO" << endl; }
	else { cout << "YES" << endl << idx + 1 << endl; }
	cin.ignore(2); return 0;
}