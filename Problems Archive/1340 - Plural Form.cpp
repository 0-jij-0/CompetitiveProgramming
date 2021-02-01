#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	if (s.back() != 's') { s.push_back('s'); }
	else { s.push_back('e'); s.push_back('s'); }
	cout << s << '\n';
	cin.ignore(2); return 0;
}