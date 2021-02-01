#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
		if (n*(a - b) > c + d) { cout << "No" << endl; continue; }
		if (n*(a + b) < c - d) { cout << "No" << endl; continue; }
		cout << "Yes" << endl;
	}
	cin.ignore(2); return 0;
}