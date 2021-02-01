#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll n, k; cin >> n >> k;
		ll s = (n + k - 1) / k;

		cout << (s * k + n - 1) / n << '\n';
	}
	cin.ignore(2); return 0;
}