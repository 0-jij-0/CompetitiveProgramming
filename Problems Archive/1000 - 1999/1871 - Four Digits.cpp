#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	cout << string(4 - s.size(), '0') << s << '\n';
	cin.ignore(2); return 0;
}