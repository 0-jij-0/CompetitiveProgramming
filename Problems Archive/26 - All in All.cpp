#include <iostream>
#include <string>
using namespace std;

string allInAll(string s, string t) {
	unsigned int i = 0;
	unsigned int j = 0;
	while (i < s.size() && j < t.size()) {
		char &c1 = s[i];
		while (j < t.size()) {
			char &c2 = t[j];
			if (c1 == c2) {	i++; j++; break; }
			j++;
		}
	}
	if (i == s.size()) { return "Yes"; }
	return "No";
}

int main() {
	while (true) {
		string s, t;
		cin >> s;
		if (cin.fail()) { break; }
		cin >> t;

		cout << allInAll(s, t) << endl;
	}
	cout << endl; cin.ignore(2); return 0;
}