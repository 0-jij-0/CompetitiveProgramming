#include <iostream>
#include <string>
using namespace std;

string s;

int missed() {
	if (s == "0") { return 0; }
	bool b1 = false; int res = 0;
	while (s.size() > 2) {
		if (s.back() == '1') { b1 = true; }
		s.pop_back();
		if (s.back() == '1') { b1 = true; }
		s.pop_back(); res++;
	}
	if (s == "1" && !b1) { return res; }
	return res + 1;
}

int main() {
	cin >> s;
	cout << missed() << endl;
	cin.ignore(2); return 0;
}