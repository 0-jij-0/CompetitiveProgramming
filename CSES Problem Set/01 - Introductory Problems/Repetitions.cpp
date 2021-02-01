#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string s; cin >> s; int n = (int)s.size();
	int i = 0, j = 0, res = 0;
	while (j != n) {
		if (s[j] == s[i]) { j++; continue; }
		res = max(res, j - i); i = j;
	}
	cout << max(res, j - i) << endl;
	cin.ignore(2); return 0;
}