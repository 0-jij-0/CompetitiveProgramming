#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> freq;

int main() {
	int n, p, k; cin >> n >> p >> k;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a; ll ak = (a * k) % p;
		a = (a * a) % p; a = (a * a) % p; 
		freq[(a - ak + p) % p]++;
	}
	ll res = 0; for (auto &x : freq)
		res += x.second * (x.second - 1) >> 1;
	cout << res << '\n'; cin.ignore(2); return 0;
}