#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	cin >> s; int n = (int)s.size();
	int min = s[0]; cout << "Mike" << endl;
	for (int i = 1; i < n; i++) {
		if (s[i] <= min) { cout << "Mike" << endl; min = s[i]; }
		else { cout << "Ann" << endl; }
	}
	cin.ignore(2); return 0;
}
