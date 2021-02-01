#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		if (n < m) { swap(n, m); }
		if (n % 2 == 0 || m % 2 == 0) { cout << (n*m) / 2 << endl; continue; }
		cout << m * (n - 1) / 2 + (m + 1) / 2 << endl;
	}
	cin.ignore(2); return 0;
}