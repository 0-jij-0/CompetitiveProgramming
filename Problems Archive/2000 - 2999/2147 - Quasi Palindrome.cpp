#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string& s) {
	int i = 0, j = (int)s.size() - 1;
	while (i < j) if (s[i++] != s[j--]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	while (s.back() == '0') s.pop_back();
	cout << (isPalindrome(s) ? "YES" : "NO") << '\n';
}