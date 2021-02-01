#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string l1, l2, l3;
bool f(string &l, char c) { return find(l.begin(), l.end(), c) != l.end(); }

string check() {
	string &s = f(l1, '=') ? l1 : f(l2, '=') ? l2 : l3;
	reverse(s.begin(), s.end()); while (s.back() != '=') { s.pop_back(); }
	s.pop_back(); reverse(s.begin(), s.end()); char c = 0;
	for (char &x : s) 
		if (x != '.') { c = x; break; }
	if (!c) { return "You shall pass!!!"; }
	else { string res; res.push_back(c); return res; }
}

int main() {
	cin >> l1 >> l2 >> l3;
	cout << check() << endl;
	cin.ignore(2); return 0;
}