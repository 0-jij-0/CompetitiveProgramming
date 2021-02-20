#include <iostream>
using namespace std;

bool isRange(char c, char a) { return c >= a && c <= a + 25; }

int main() {
	string s; cin >> s; bool b = true;
	for (int i = 0; i < (int)s.size(); i++) 
		if (!isRange(s[i], i % 2 ? 'A' : 'a')) { b = false; break; }
	cout << (b ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}