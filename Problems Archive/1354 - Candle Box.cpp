#include <iostream>
using namespace std;

int main() {
	int d, r, t; cin >> d >> r >> t; 
	int s = r + t, res = 0;
	for (int n = d; n < 100; n++) {
		int R = ((7 + n) * n) / 2;
		int T = ((6 + n - d) * (n - d + 1)) / 2;
		if (r - R < 0 || r - R != T - t) { continue; }
		res = T - t; break;
	} 
	cout << res << '\n';
	cin.ignore(2); return 0;
}