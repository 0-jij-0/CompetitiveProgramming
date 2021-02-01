#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1000 * 1000 * 1000 + 7;

ll power2(int n) {
	if (!n) { return 1; }
	ll res = power2(n >> 1);
	res = (res * res) % mod;
	if (n % 2 == 0) { return res; }
	return (2 * res) % mod;
}
int main() {
	int n; cin >> n; cout << power2(n) << endl;
	cin.ignore(2); return 0;
}