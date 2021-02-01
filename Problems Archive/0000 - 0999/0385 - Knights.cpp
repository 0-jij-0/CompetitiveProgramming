#include <iostream>
using namespace std;

char c[2] = { 'B', 'W' };

int main() {
	int n; cin >> n;
	bool b = true;
	for (int i = 0; i < n; i++) {
		bool ch = b;
		for (int j = 0; j < n; j++) { cout << c[ch]; ch = !ch; }
		cout << endl; b = !b;
	}
	cin.ignore(2); return 0;
}