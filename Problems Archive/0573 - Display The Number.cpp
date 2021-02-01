#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		string s(n / 2, '1');
		if (n % 2) { s[0] = '7'; }
		cout << s << endl;
	}
	cin.ignore(2); return 0;
}