#include <iostream>
using namespace std;

int main() {
	int n; cin >> n; int res = 0;
	for (int i = 0; i < n; i++) {
		int p, q; cin >> p >> q;
		res += (q - p) > 1;
	}
	cout << res << endl;
	cin.ignore(2); return 0;
}