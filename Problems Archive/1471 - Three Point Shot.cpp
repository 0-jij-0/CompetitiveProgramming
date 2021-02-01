#include <iostream>
using namespace std;

int main() {
	int x, y; cin >> x >> y;
	cout << (abs(x - y) < 3 ? "Yes" : "No") << '\n';
	cin.ignore(2); return 0;
}