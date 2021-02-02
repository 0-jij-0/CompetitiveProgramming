#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll nC2[100001];
ll one, zero;

bool check(ll a, ll b, ll c, ll d) {
	int ia = lower_bound(nC2, nC2 + 100001, a) - nC2;
	int id = lower_bound(nC2, nC2 + 100001, d) - nC2;
	if (!ia && (b || c)) { ia = 1; }
	if (!id && (b || c)) { id = 1; }
	if (nC2[ia] != a || nC2[id] != d) { return false; }
	if (a + b + c + d != nC2[ia + id]) { return false; }
	one = id; zero = ia; return true;
}

int main() {
	for (ll i = 0; i < 100001; i++) { nC2[i] = (i * (i - 1)) / 2; }
	ll a, b, c, d; cin >> a >> b >> c >> d;
	if (a + b + c + d == 0) { cout << "0" << endl; cin.ignore(2); return 0; }

	if (!check(a, b, c, d)) { cout << "impossible" << endl; cin.ignore(2); return 0; }
	if (one == 0) { cout << string(zero, '0') << endl; cin.ignore(2); return 0; }
	if (zero == 0) { cout << string(one, '1') << endl; cin.ignore(2); return 0; }

	ll x = b / one, y = b % one, z = zero - x - (y != 0);

	string zero1(x, '0'), one2(y, '1'), one1(one - y, '1'), zero2(z, '0');
	if (y == 0) { cout << zero1 << one1 << zero2 << endl; }
	else { cout << zero1 << one1 << "0" << one2 << zero2 << endl; }
	cin.ignore(2); return 0;
}