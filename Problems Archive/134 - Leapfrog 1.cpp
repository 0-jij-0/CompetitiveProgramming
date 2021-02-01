#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string s; cin >> s;
		int empty = 0, b = 0;
		for (unsigned int j = 1; j < s.size(); j++) {
			if (s[j] == '.') { empty++; }
			else { b++; }
		}
		cout << "Case #" << i + 1 << ": ";
		if (empty == 0 || empty > b) { cout << 'N' << endl; }
		else { cout << 'Y' << endl; }
	}
	cin.ignore(2); return 0;
}