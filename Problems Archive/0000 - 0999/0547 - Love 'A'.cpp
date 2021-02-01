#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	int a = 0;
	for (char &c : s)
		a += (c == 'a');
	cout << min((int)s.size(), 2 * a - 1) << endl;
	cin.ignore(2); return 0;
}