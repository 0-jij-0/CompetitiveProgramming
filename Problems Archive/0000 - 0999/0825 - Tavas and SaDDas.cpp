#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int toDecimal(int n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	n = (int)s.size(); int res = 0;
	for(int i = 0; i < n; i++)
		if (s[i] == '7') { res += 1 << i; }
	return res;
}

int main() {
	int n; cin >> n; int m = n;
	int c = 0; while (m) { c++; m /= 10; }
	int less = (1 << c) - 2;
	cout << less + toDecimal(n) + 1 << endl;
	cin.ignore(2); return 0;
}