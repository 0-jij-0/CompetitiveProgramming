#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n == 1) { cout << -1 << endl; continue; }
		string s(n, '3'); s[n - 1] = '4'; cout << s << endl;
	}
	cin.ignore(2); return 0;
}