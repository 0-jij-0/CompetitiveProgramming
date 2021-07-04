#include <iostream>
using namespace std;

int main() {
	int t; cin >> t; while (t--) {
		int n, e = 0, o = 0; cin >> n; n <<= 1;
		while (n--) { int x; cin >> x; (x & 1 ? o : e)++; }
		cout << (e == o ? "Yes" : "No") << '\n';
	}
	cin.ignore(2); return 0;
}