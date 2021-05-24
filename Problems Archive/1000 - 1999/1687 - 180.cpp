#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s; cin >> s;
	reverse(s.begin(), s.end());
	for (char& c : s)
		c = (c == '9') ? '6' : (c == '6' ? '9' : c);

	cout << s << '\n';
	cin.ignore(2); return 0;
}