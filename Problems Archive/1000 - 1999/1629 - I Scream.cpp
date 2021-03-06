#include <iostream>
using namespace std;

int main() {
	int a, b; cin >> a >> b; a += b;
	if (a >= 15 && b >= 8) { cout << 1 << '\n'; }
	else if (a >= 10 && b >= 3) { cout << 2 << '\n'; }
	else if (a >= 3) { cout << 3 << '\n'; }
	else { cout << 4 << '\n'; }
	cin.ignore(2); return 0;
}