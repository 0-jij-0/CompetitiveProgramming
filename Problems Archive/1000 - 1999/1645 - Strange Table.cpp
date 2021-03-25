#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll n, m, x; cin >> n >> m >> x; x--;
		ll j = x / n, i = x % n;
		cout << i * m + j + 1 << '\n';
	}
	cin.ignore(2); return 0;
}