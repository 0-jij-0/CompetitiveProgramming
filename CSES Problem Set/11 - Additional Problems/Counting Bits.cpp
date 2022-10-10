#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n; ll res = 0; n++;
	for (int i = 0; i < 50; i++) {
		ll mask = 1ll << (i + 1);
		res += (n / mask) * (mask >> 1);
		res += max(0ll, n % mask - (mask >> 1));
	}
	cout << res << '\n';
}