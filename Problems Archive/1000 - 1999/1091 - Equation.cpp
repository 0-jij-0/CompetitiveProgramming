#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2) { cout << 9 + n << ' ' << 9 << '\n'; }
	else { cout << 4 + n << ' ' << 4 << '\n'; }
	cin.ignore(2); return 0;
}