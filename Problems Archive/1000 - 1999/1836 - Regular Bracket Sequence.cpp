#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; 
		for (int i = 0; i < n; i++) {
			string L = string(n - i, '(') + string(n - i, ')');
			string R = string(i, '(') + string(i, ')');
			cout << L + R << '\n';
		}
	}
	cin.ignore(2); return 0;
}