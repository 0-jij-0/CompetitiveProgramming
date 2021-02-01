#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		if (m <= n/k) { cout << m << endl; continue; }
		cout << (n / k) - (m - (n / k) + k - 2) / (k - 1) << endl;
	}
	cin.ignore(2); return 0;
}