#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int avg = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a; avg += a;
		}
		cout << (avg + n - 1) / n << endl;
	}
	cin.ignore(2); return 0;	
}