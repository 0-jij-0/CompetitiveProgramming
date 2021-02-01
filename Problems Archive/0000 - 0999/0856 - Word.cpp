#include <iostream>
#include <string>
using namespace std;

string s; int n;

bool isLower(char &c) { return c >= 'a' && c <= 'z'; }

void toLower() {
	for (int i = 0; i < n; i++)
		if (!isLower(s[i])) s[i] += 'a' - 'A';
}

void toUpper() {
	for (int i = 0; i < n; i++)
		if (isLower(s[i])) s[i] += 'A' - 'a';
}

int main() {
	cin >> s; n = (int)s.size();
	int u = 0, l = 0;
	for (char &c : s)
		(isLower(c) ? l : u)++;
	u > l ? toUpper() : toLower();
	cout << s << endl;
	cin.ignore(2); return 0;
}