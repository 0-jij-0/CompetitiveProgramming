#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s; int res = 0;
	for (int i = 0; i < (int)s.size(); i++)
		res += (s[i] != 'P') + (s[++i] != 'E') + (s[++i] != 'R');
	cout << res << '\n'; cin.ignore(2); return 0;
}