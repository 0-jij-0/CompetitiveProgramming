#include <iostream>
#include <string>
using namespace std;

string a, b;

int main() {
	int t; cin >> t; getline(cin, a);
	while (t--) {
		getline(cin, a); getline(cin, b);
		a = a.substr(9); b = b.substr(9);
		cout << "Uh! " << b << '-' << a << '!' << '\n';
	}
	cin.ignore(2);; return 0;
}