#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a > b) { swap(a, b); }
		if (2 * a < b) { cout << "NO\n"; continue; }
		a -= (b - a); cout << (a % 3 ? "NO" : "YES") << '\n';
	}
}