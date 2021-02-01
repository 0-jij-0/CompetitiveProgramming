#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		int n; cin >> n; ll res = 0;
		while (n--) {
			ll x; cin >> x;
			while (x & 1) { x >>= 1; }
			res ^= x >> 1;
		}
		cout << (res ? "YES" : "NO") << '\n';
	}
	cin.ignore(2); return 0;
}