#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int R[3], N[3], P[3];

bool check(ll M, ll k) {
	ll res = 0;
	for (int i = 0; i < 3; i++)
		res += max(0ll, R[i] * M - N[i]) * P[i];
	return res <= k;
}

ll maxHamburgers(ll k) {
	ll l = 0, r = 1ll << 40;
	while (l != r) {
		ll mid = (l + r + 1) >> 1;
		check(mid, k) ? l = mid : r = mid - 1;
	}
	return l;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s; cin >> s;
	for (char c : s)
		if (c == 'B') R[0]++;
		else if (c == 'S') R[1]++;
		else R[2]++;

	cin >> N[0] >> N[1] >> N[2];
	cin >> P[0] >> P[1] >> P[2];
	ll r; cin >> r;

	cout << maxHamburgers(r) << '\n';
}