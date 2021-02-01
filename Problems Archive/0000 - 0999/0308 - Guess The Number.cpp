#include <iostream>
#include <string>
using namespace std;

int main() {
	int l = 0, r = 1000000;
	while (l != r) {
		int mid = (l + r + 1) >> 1;
		cout << mid << endl; fflush(stdout);
		string s; cin >> s;
		if (s == "<") { r = mid - 1; continue; }
		else { l = mid; }
	}
	cout << "! " << l << endl; fflush(stdout);
	cin.ignore(2); return 0;
}