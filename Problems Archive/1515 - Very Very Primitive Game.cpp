#include <iostream>
using namespace std;

int main() {
	int a, b, c; cin >> a >> b >> c;
	bool ok = (a != b && a > b) || (a == b && c);
	cout << (ok ? "Takahashi" : "Aoki") << '\n';
	cin.ignore(2); return 0;
}