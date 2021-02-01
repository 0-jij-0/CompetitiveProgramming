#include <iostream>
using namespace std;

int main() {
	int x, y, z; cin >> x >> y >> z;
	int diff = abs(x - y);
	if (diff < z || (z != 0 && diff == z)) { cout << '?' << endl; }
	else if (x > y) { cout << '+' << endl; }
	else if (y > x) { cout << '-' << endl; }
	else { cout << '0' << endl; }
	cin.ignore(2); return 0;
}