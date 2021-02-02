#include <iostream>
using namespace std;

int main() {
	int p, q; cin >> p >> q;
	if (p % 2 == 0) { cout << 0 << endl; }
	else if (q % 2) { cout << 1 << endl; }
	else if (p < q) { cout << 2 << endl; }
	else { cout << 0 << endl; }
	cin.ignore(2); return 0;
}