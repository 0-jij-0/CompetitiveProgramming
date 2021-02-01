#include <iostream>
using namespace std;

int main() {
	int x; cin >> x; x %= 4;
	if (x == 0) { cout << 1 << " A" << endl; }
	else if (x == 1) { cout << 0 << " A" << endl; }
	else if (x == 2) { cout << 1 << " B" << endl; }
	else { cout << 2 << " A" << endl; }
	cin.ignore(2); return 0;
}