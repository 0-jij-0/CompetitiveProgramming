#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, m, k;

bool check(ll x){
	ll less = 0;
	for (ll i = 1; i <= n; i++)
		less += min((x - 1) / i, m);

	return less < k;
}

ll find_kth() {
	ll l = 0, r = n * m;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		bool b = check(mid);
		b ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	cin >> n >> m >> k;
	cout << find_kth() << endl;
	cin.ignore(2); return 0;
}