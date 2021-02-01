#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2) { cout << 9 << ' ' << n - 9 << endl; }
	else { cout << 8 << ' ' << n - 8 << endl; }
	cin.ignore(2); return 0;
}