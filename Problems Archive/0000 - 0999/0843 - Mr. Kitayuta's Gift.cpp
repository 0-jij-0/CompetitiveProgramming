#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string &s, int i, int j) {
	while (i < j) if (s[i++] != s[j--]) return false;
	return true;
}

bool makePalindrome(string &s) {
	int i = 0, j = (int)s.size() - 1;
	while (i < j) {
		if (s[i] == s[j]) { i++; j--; continue; }
		if (isPalindrome(s, i + 1, j)) {
			if (j == (int)s.size() - 1) { s.push_back(s[i]); }
			else { s.insert(s.begin() + j + 1, s[i]); }
			return true;
		}
		if (isPalindrome(s, i, j - 1)) {
			s.insert(s.begin() + i, s[j]);
			return true;
		}
		return false;
	}
	int mid = (int)s.size() / 2;
	s.insert(s.begin() + mid, s[mid]);
	return true;
}

int main() {
	string s; cin >> s;
	if (!makePalindrome(s)) { cout << "NA" << endl; }
	else { cout << s << endl; }
	cin.ignore(2); return 0;
}