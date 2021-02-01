#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; string s; cin >> n >> s;
		cout << string(n, s[n - 1]) << '\n';
	}
	cin.ignore(2); return 0;
}