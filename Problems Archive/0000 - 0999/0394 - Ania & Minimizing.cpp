#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int n, k; cin >> n >> k >> s;
	if (k != 0 && n == 1) { cout << 0 << endl; }
	else {
		bool b = true; int i = 0;
		for (; i < n; i++) {
			if (k == 0) { break; }
			if (s[i] > '0' + b) { s[i] = '0' + b; k--; }
			b = false;
		}
		cout << s << endl;
	}
	cin.ignore(2); return 0;
}