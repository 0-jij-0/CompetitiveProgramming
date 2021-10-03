#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll a, b; cin >> a >> b; ll c = a - b;
	ll res = 1; while (c--) { res <<= 5; }
	cout << res << '\n';
}