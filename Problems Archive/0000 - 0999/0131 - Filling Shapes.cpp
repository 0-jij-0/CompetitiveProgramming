#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2 == 1) { cout << 0 << endl; }
	else { cout << (int)floor(pow(2.0, (n + 0.0) / 2.0)) << endl; }
	cin.ignore(2); return 0;
}