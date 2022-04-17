#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	int res = 0;
	for (int i = 0; i < 9; i++)
		res ^= (s[i] - '0') ^ i;

	cout << (res ^ 9) << '\n';
	cin.ignore(2); return 0;
}