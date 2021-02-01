#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		bool e = false, o = false;
		int sum = 0;
		while (n--) {
			int a; cin >> a; sum += a;
			e = e || (a % 2 == 0);
			o = o || (a % 2);
		}
		if (sum % 2) { cout << "YES" << endl; continue; }
		if (e && o) { cout << "YES" << endl; continue; }
		cout << "NO" << endl;
	}
	cin.ignore(2); return 0;
}