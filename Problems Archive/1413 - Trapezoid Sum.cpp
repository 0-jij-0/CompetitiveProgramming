#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n; ll res = 0;
	for (int i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		res += b * (b + 1) / 2 - a * (a - 1) / 2;
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}