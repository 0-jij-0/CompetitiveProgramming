#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n, d; cin >> n >> d;
		if (d <= n) { cout << "YES" << endl; continue; }
		bool b = false;
		for (int i = 1; i * i <= d; i++) {
			if (i + ((d + i) / (i + 1)) <= n) { 
				cout << "YES" << endl; 
				b = true; break;
			}
		}
		if(!b) { cout << "NO" << endl; }
	}
	cin.ignore(2); return 0;
}