#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; getline(cin, s); bool b = true;
	int i = 0, j = 1, n = (int)s.size();
	while (j != n) {
		if (s[j] == ' ') { j++; continue; }
		if (j - i + 1 < 4) { b = false; break; }
		i = j; j++;
	}
	cout << (b ? "safe" : "unsafe") << endl;
	cin.ignore(2); return 0;
}