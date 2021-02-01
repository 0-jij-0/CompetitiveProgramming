#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << (b - (a % b)) % b << endl;
	}
	cin.ignore(2); return 0;
}