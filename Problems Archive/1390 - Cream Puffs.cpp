#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

set<ll> res;

int main() {
	ll n; cin >> n;
	for(ll i = 1; i * i <= n; i++)
		if (n % i == 0) { res.insert(i); res.insert(n / i);	}

	for (auto &x : res) cout << x << '\n';
}