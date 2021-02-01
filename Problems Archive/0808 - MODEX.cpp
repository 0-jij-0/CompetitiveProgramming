#include <iostream>
using namespace std;
typedef long long ll;

ll power(int x, int y, const int &m) {
	if (!y) { return 1; }
	ll res = power(x, y >> 1, m);
	res = (res*res) % m;
	if (y & 1) { return (res * x) % m; }
	return res;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int x, y, m; cin >> x >> y >> m;
		cout << power(x, y, m) << endl;
	}
	cin.ignore(2); return 0;
}