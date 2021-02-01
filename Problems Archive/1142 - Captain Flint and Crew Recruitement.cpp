#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (n <= 30) { cout << "NO" << endl; continue; }
		cout << "YES" << endl; n -= 30; 
		if (n == 6 || n == 10 || n == 14)
			cout << "6 10 15 " << n - 1 << endl;
		else cout << "6 10 14 " << n << endl;
	}
	cin.ignore(2); return 0;
}