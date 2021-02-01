#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; if (n == 1) { cout << '9' << '\n'; continue; }
		string s(n, '0'); s[0] = '9'; s[1] = '8'; int cur = 9;
		for (int i = 2; i < n; i++) { s[i] = cur + '0'; cur = (cur + 1) % 10; }
		cout << s << '\n';
	}
	cin.ignore(2); return 0;
}