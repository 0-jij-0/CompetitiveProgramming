#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; string s; cin >> n >> s;
	int res = 0, i = 0, j = 0, p = 0;
	while (j != n) {
		p += (s[j] == '(') ? 1 : -1;
		if (p) { j++; continue; }
		res += (s[i] == '(') ? 0 : j - i + 1;
		i = j = j + 1;
	}
	cout << (p ? -1 : res) << endl;
	cin.ignore(2); return 0;
}