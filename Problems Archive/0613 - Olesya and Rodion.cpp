#include <iostream>
#include <string>
using namespace std;

string findNum(int n, int t) {
	if (n == 1 && t == 10) { return "-1"; }
	if (t == 10) { string s(n, '1'); s[n - 1] = '0'; return s; }
	return string(n, t + '0');
}

int main() {
	int n, t; cin >> n >> t;
	cout << findNum(n, t) << endl;
	cin.ignore(2); return 0;
}