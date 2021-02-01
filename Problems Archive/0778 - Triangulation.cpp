#include <iostream>
using namespace std;

int minDiameter(int n) {
	if (n == 3) { return 0; }
	if (n == 4) { return 1; }
	if (n == 5) { return 2; }
	if (n == 6) { return 2; }

	return 2 + +minDiameter((n + 1) >> 1);
}

int main() {
	int n; cin >> n;
	cout << minDiameter(n) << endl;
	cin.ignore(2); return 0;
}