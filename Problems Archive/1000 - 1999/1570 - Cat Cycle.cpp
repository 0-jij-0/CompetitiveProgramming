#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll n, k; cin >> n >> k; k--;
		if (!(n & 1)) { cout << (k % n) + 1 << '\n'; continue; }
		ll mid = n >> 1;
		ll res = (k / mid) * (mid + 1) + (k % mid);
		cout << 1 + (res % n) << '\n';
	}
	cin.ignore(2); return 0;
}