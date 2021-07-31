#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> v; ll res = 0;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return (b / gcd(a, b)) * a; }

bool check(ll f) {
	ll A = v[0].first, B = v[0].second;
	for (int i = 1; i < (int)v.size(); i++) {
		ll C1A = gcd(A, v[i].first), C1B = gcd(B, v[i].second);
		if (lcm(C1A, C1B) % f == 0) { A = C1A; B = C1B; continue; }

		ll C2A = gcd(A, v[i].second), C2B = gcd(B, v[i].first);
		if (lcm(C2A, C2B) % f == 0) { A = C2A; B = C2B; continue; }

		return false;
	}
	return true;
}

void getDivisorsHelper(int i, ll cur, vector<pair<int, int>>& V) {
	if (i == (int)V.size()) { if (check(cur)) res = max(res, cur); return; }

	getDivisorsHelper(i + 1, cur, V);
	for (int j = 0; j < V[i].second; j++) {
		cur *= V[i].first;
		getDivisorsHelper(i + 1, cur, V);
	}
}

void getDivisors(ll x) {
	vector<pair<int, int>> res;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i) { continue; }
		int e = 0; while (x % i == 0) { x /= i; e++; }
		res.emplace_back((int)i, e);
	}
	if (x != 1) { res.emplace_back((int)x, 1); }
	getDivisorsHelper(0, 1, res);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	ll GCDofLCM = 0; for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second; 
		ll L = lcm(v[i].first, v[i].second);
		GCDofLCM = gcd(GCDofLCM, L);
	}

	getDivisors(GCDofLCM); cout << res << '\n';
	cin.ignore(2); return 0;
}