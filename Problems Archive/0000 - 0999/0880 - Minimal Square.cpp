#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (a > b) { swap(a, b); }
		cout << max(4 * a*a, b*b) << endl;
	}
	cin.ignore(2); return 0;
}