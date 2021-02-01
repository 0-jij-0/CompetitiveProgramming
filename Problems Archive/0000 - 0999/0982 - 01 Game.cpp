#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int z = 0, o = 0;
		for (char &c : s) (c - '0' ? o : z)++;
		cout << (min(z, o) % 2 ? "DA" : "NET") << '\n';
	}
	cin.ignore(2); return 0;
}