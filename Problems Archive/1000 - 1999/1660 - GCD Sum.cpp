#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int digSum(ll x) {
	int res = 0; 
	while (x) { res += x % 10; x /= 10; }
	return res;
}

int main() {
	int t; cin >> t; while (t--) {
		ll n; cin >> n;
		while (gcd(n, digSum(n)) == 1) { n++; }
		cout << n << '\n';
	}
	cin.ignore(2); return 0;
}