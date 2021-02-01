#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll power10(ll x) {
	ll res = x; res *= res;
	res *= res; res *= x;
	return res * res;
}

string ans = "codeforces";

int main() {
	ll k; cin >> k; vector<int> v(10, 1);
	int p = 1; while (power10(p + 1) < k) { p++; }
	for (auto &x : v) { x *= p; }
	ll res = power10(p); int i = 0;
	while (res < k) { v[i++] = p + 1; res = (res / p)*(p + 1); }
	for (int i = 0; i < 10; i++) { cout << string(v[i], ans[i]); }
	cout << '\n'; cin.ignore(2); return 0;
}