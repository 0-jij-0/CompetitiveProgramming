#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, t; cin >> s >> t;
	cout << (s < t ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}