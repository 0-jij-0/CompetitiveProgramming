#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s; int c = 0, n = (int)s.size();
	if (s[0] == 'h') { cout << "http://"; c = 4; }
	else { cout << "ftp://"; c = 3; }
	if (s[n - 1] == 'u' && s[n - 2] == 'r') { cout << s.substr(c, n - 2 - c) << ".ru" << endl; }
	else for (int i = n - 2; i > c; i--)
		if (s[i] == 'u' && s[i - 1] == 'r') {
			cout << s.substr(c, i - 1 - c) << ".ru/" << s.substr(i + 1) << endl; break;
		}
	cin.ignore(2); return 0;
}
