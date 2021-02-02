#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> p;
int n;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

long long area() {
	ll a = 0;
	for (int i = 0; i < n; i++)
		a += (p[i].first*p[i + 1].second - p[i + 1].first*p[i].second);
	return abs(a);
}

long long boundary() {
	ll B = 0;
	for (int i = 0; i < n; i++) {
		ll x = abs(p[i].first - p[i + 1].first);
		ll y = abs(p[i].second - p[i + 1].second);
		B += gcd(x, y);
	}
	return B;
}

int main() {
	cin >> n; p.resize(n);
	for (auto &x : p) { cin >> x.first >> x.second; }
	p.push_back({ p[0].first, p[0].second });
	ll A = area(), B = boundary();
	cout << (A - B + 2) / 2 << endl;
	cin.ignore(2); return 0;
}