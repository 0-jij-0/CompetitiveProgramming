#include <iostream>
using namespace std;

typedef long long ll;
ll n, p, w, d;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll modInverse(ll a, ll m) {
	a = a % m;
	for (ll x = 1; x < m; x++)
		if ((a * x) % m == 1) { return x; }
	return -1;
}

int main() {
	cin >> n >> p >> w >> d;
	if (p / w > n || (p / w == n && p % w)) { cout << -1 << endl; return 0; }
	if (p == 0) { cout << 0 << ' ' << 0 << ' ' << n << endl; return 0; }

	ll x = p - (p / w) * w;
	ll y = (x + d - 1) / d; y = y * d - x;
	ll g = gcd(w, d); 
	if (y % g) { cout << -1 << endl; return 0; }

	ll new_w = w / g; y /= g; ll new_d = d / g;
	ll inv = modInverse(new_w, new_d);
	y *= inv; 
	y %= new_d;

	ll wins = p / w - y, draws = (y * w + x) / d, losses = n - wins - draws;
	if (wins < 0 || draws < 0 || losses < 0) { cout << -1 << endl; return 0; }
	cout << wins << ' ' << draws << ' ' << losses << endl;
	cin.ignore(2); return 0;
}