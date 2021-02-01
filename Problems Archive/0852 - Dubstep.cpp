#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string s;

int main() {
	cin >> s; int n = (int)s.size();
	if (n < 3) { cout << s << endl; return 0; }
	while (n >= 3 && s.substr(n - 3) == "WUB") {
		s.erase(s.begin() + n - 3, s.end()); n -= 3;
	}
	if (n < 3) { cout << s << endl; return 0; }
	while (n >= 3 && s.substr(0, 3) == "WUB") {
		s.erase(s.begin(), s.begin() + 3); n -= 3;
	}
	if (n < 3) { cout << s << endl; return 0; }

	int i = 0;
	while (i < (int)s.size() - 2) {
		if (s.substr(i, 3) != "WUB") { i++; continue; }
		s.erase(s.begin() + i, s.begin() + i + 3);
		if (s[i - 1] != ' ') { s.insert(s.begin() + i, ' '); i++; }
	}
	cout << s << endl;
	cin.ignore(2); return 0;
}