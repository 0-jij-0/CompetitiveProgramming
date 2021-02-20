#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 61;

string s; ll m; int n;

bool check(ll b) {
	ll cur = 0, c = 1;
	for (int i = 1; i < n && c <= m; i++) c *= b;
	if (c > m) { return false; }
	for (int i = 0; i < n && cur <= m; i++, c /= b)
		cur += c * (s[i] - '0');
	return cur <= m;
}

int main() {
	cin >> s >> m; n = (int)s.size();
	if (n == 1) { cout << (m >= s[0] - '0') << '\n'; return 0; }

	int x = *max_element(s.begin(), s.end()) - '0';
	int f = log(s[0] - '0'); double b = log(INF);

	ll l = x, r = INF; while (l != r) {
		ll mid = (l + r + 1) >> 1;
		if (f + (n - 1) * log(mid) > b) { r = mid - 1; continue; }
		check(mid) ? l = mid : r = mid - 1;
	}
	cout << l - x << '\n';
	cin.ignore(2); return 0;
}