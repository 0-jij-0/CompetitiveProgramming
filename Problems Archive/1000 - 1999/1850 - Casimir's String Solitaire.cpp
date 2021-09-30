#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		string s; cin >> s; int n = (int)s.size();
		int b = count(s.begin(), s.end(), 'B');
		cout << (b == n / 2 ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}