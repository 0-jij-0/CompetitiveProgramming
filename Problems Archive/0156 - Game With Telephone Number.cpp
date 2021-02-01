#include <iostream>
#include <string>
using namespace std;

const int f = 8;

int main() {
	int n; cin >> n;
	int count = 0;
	for (int i = 0; i < n - 10; i++) {
		char c; cin >> c;
		if (c == f + '0') { count++; }
	}
	string left; cin >> left;
	if (count > (n - 10) / 2) { cout << "YES" << endl; }
	else { cout << "NO" << endl; }
	cin.ignore(2); return 0;
}