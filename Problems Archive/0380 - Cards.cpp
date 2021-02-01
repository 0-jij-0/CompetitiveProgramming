#include <iostream>
#include <string>
using namespace std;

int z, n1; string s, res;

int main() {
	int n; cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'z') { z++; continue; }
		if (s[i] == 'n') { n1++; continue; }
	}
	string one(n1, '1'), zero(z, '0'); res = one + zero;
	for (auto &c : res) { cout << c << ' '; } cout << endl;
	cin.ignore(2); return 0;
}