#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n0, n1, n2; cin >> n0 >> n1 >> n2;
		if (n0 + n2 == 0) {
			cout << 0; 
			while (n1 > 1) { cout << 10; n1 -= 2; }
			if (n1) { cout << 1; }
			cout << endl; continue;
		}
		if (n1 + n2 == 0) { cout << string(n0 + 1, '0') << endl; continue; }
		if (n1 + n0 == 0) { cout << string(n2 + 1, '1') << endl; continue; }
		if (n1 == 1) { cout << string(n0 + 1, '0') << string(n2 + 1, '1') << endl; continue; }
		cout << string(n0 + 1, '0'); while (n1 > 2) { cout << 10; n1 -= 2; }
		cout << string(n2 + 1, '1'); if (n1 == 2) { cout << 0; }
		cout << endl;
	}
	cin.ignore(2); return 0;
}