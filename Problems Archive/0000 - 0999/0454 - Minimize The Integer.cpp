#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;

bool compare(const char &c1, const char &c2) {
	if (abs(c1 - c2) % 2) { return c1 < c2; }
	return false;
}
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> s; int n = (int)s.size();
		string s1, s2;
		for(auto &c:s)
			if (c % 2) { s1.push_back(c); }
			else { s2.push_back(c); }
		merge(s1.begin(), s1.end(), s2.begin(), s2.end(), s.begin(), compare);
		cout << s << endl;
	}
	cin.ignore(2); return 0;
}