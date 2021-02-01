#include <iostream>
using namespace std;
typedef long long ll;

void find(ll u, ll v) {
	if (u > v || (v - u) % 2) { cout << -1 << endl; return; }
	if (u == v && !u) { cout << 0 << endl; return; }
	if (u == v) { cout << 1 << endl << u << endl; return; }
	ll x = (v - u) >> 1;
	if (!(x & u)) { cout << 2 << endl << u + x << ' ' << x << endl; return; }
	cout << 3 << endl << u << ' ' << x << ' ' << x << endl;
}

int main() {
	ll u, v; cin >> u >> v;
	find(u, v);
	cin.ignore(2); return 0;
}