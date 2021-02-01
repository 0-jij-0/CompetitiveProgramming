#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t;
	while (t--) {
		ll n, r; cin >> n >> r;
		if (r < n) { cout << r * (r + 1) / 2 << endl; continue; }
		cout << n * (n - 1) / 2 + 1 << endl;
	}
	cin.ignore(2); return 0;
}