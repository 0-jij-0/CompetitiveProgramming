#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll q, n; cin >> q >> n;
		ll res = 0, c = 1, count = n;
		while (q) {
			if (count >= q) { res += q * c; q = 0; continue; }
			res += c * count; q -= count; count *= n; c++;
		}
		cout << res << endl;
	}
	cin.ignore(2); return 0;
}