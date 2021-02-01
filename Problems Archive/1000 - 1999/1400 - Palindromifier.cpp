#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s; int n = (int)s.size();
	cout << 3 << '\n';
	cout << "L 2" << '\n';
	cout << "R " << 2 << '\n';
	cout << "R " << 2*n - 1 << '\n';
	cin.ignore(2); return 0;
}