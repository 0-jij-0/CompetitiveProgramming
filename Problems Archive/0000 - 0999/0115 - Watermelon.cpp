#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	if (n % 2 == 1) { cout << "NO" << endl; }
	else if (n == 2) { cout << "NO" << endl; }
	else { cout << "YES" << endl; }
	cin.ignore(2); return 0;
}