#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << (n % 4 ? "NO" : "YES") << '\n';
	}
	cin.ignore(2); return 0;
}