#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		cout << (-n + 1) << ' ' << n << '\n';
	}
	cout << '\n'; cin.ignore(2); return 0;
}