#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		string s; cin >> s; char ma = '0';
		for (char& c : s) ma = max(ma, c);
		cout << ma << '\n';
	}

	cin.ignore(2); return 0;
}