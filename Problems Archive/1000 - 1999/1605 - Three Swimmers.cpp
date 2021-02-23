#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	int t; cin >> t; while (t--) {
		ll p, a, b, c; cin >> p >> a >> b >> c;
		ll A = (a - (p % a)) % a;
		ll B = (b - (p % b)) % b;
		ll C = (c - (p % c)) % c;
		cout << min({ A, B, C }) << '\n';
	}
	cin.ignore(2); return 0;
}