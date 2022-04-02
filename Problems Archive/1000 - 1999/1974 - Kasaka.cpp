#include <iostream>
#include <string>
using namespace std;

bool check(string& s) {
	int i = 0, j = (int)s.size(); j--;
	while (i < j && s[j] == 'a' && s[i] == s[j]) { i++; j--; }
	while (s[j] != s[i]) if (s[j--] != 'a') return false;
	while(i < j) if(s[i++] != s[j--]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	cout << (check(s) ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}