#include <iostream>
#include <string>
using namespace std;

string s, t;

int main() {
	cin >> s >> t;
	int i = (int) s.size() - 1;
	while (s[i] == 'z') { s[i] = 'a'; i--; }
	s[i]++; cout << (s == t ? "No such string" : s) << endl;
	cin.ignore(2); return 0;
}