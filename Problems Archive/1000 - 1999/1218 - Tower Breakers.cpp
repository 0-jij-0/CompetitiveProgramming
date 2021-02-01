#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m; 
		if ((n & 1) == 0) { cout << 2 << '\n'; continue; }
		if (m == 1) { cout << 2 << '\n'; continue; }
		cout << 1 << '\n';
	}
	cin.ignore(2); return 0;
}