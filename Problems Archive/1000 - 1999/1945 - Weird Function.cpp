#include <iostream>
using namespace std;

int f(int x) {
	return x * x + 2 * x + 3;
}

int main() {
	int x; cin >> x;
	cout << f(f(f(x) + x) + f(f(x))) << '\n';
	cin.ignore(2); return 0;
}