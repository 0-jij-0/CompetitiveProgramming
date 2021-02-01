#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 998244353;

map<ll, vector<pair<ll, int>>> primeDiv;
vector<ll> fact;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
void fillFact() {
	fact.push_back(1);
	for (int i = 1; i <= 100; i++)
		fact.push_back((fact.back() * i) % mod);
}

void getDivisorsHelper(int i, ll curr, vector<pair<ll, int>> &p, vector<pair<ll, int>> &v) {
	if (i == (int)v.size()) { primeDiv[curr] = p; return; }
	getDivisorsHelper(i + 1, curr, p, v);
	p.push_back({ v[i].first, 0 });
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first; p.back().second++;
		getDivisorsHelper(i + 1, curr, p, v);
	}
	p.pop_back();
}

void getDivisors(ll x) {
	vector<pair<ll, int>> v; vector<pair<ll, int>> p;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i) { continue; }
		int c = 0; while (!(x % i)) { c++; x /= i; }
		v.push_back({ i, c });
	}
	if (x != 1) { v.push_back({ x, 1 }); }
	getDivisorsHelper(0, 1, p, v);
}

ll power(ll x, ll n) {
	if (!n) { return 1; }
	ll res = power(x, n >> 1);
	res = (res * res) % mod;
	if (n & 1) { return (res * x) % mod; }
	return res;
}

//Assumes mod is prime
ll modInv(ll x) { return power(x, mod - 2); }

ll findPath(ll s, ll d) {
	if (s == d) { return 1; }
	ll target = s / d;
	ll num = 0, denum = 1;
	for (auto &x : primeDiv[target]) { 
		denum *= fact[x.second];
		num += x.second; denum %= mod;
	}
	num = fact[(int)num];
	return (num * modInv(denum)) % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n; int q; cin >> n >> q; 
	getDivisors(n); fillFact();
	while (q--) {
		ll u, v; cin >> u >> v;	ll g = gcd(u, v);
		cout << (findPath(u, g) * findPath(v, g)) % mod << '\n';
	}
	cin.ignore(2); return 0;
}