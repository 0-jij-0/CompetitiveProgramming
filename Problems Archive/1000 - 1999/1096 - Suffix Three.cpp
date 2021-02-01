#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		if (s.back() == 'o') { cout << "FILIPINO" << endl; continue; }
		if (s.back() == 'u') { cout << "JAPANESE" << endl; continue; }
		cout << "KOREAN" << endl;
	}
	cin.ignore(2); return 0;
}