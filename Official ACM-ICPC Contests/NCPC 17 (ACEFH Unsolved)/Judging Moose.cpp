#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	if (!n && !m) { cout << "Not a moose"; }
	else if (n == m) { cout << "Even " << 2 * n; }
	else { cout << "Odd " << 2 * max(n, m); }
	cout << endl; cin.ignore(2); return 0;
}