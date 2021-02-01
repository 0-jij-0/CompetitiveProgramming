#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		(c == 'L' ? l : r)++;
	}
	cout << l + r + 1 << endl;
	cin.ignore(2); return 0;
}