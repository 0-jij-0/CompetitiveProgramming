#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b; int g = gcd(a, b);
		cout << (g == 1 ? "Finite" : "Infinite") << endl;
	}
	cin.ignore(2); return 0;
}