#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#pragma GCC optimize("Ofast")
using namespace std;
typedef unsigned long long ll;

vector<pair<int, int>> pf;
vector<ll> divi; int b;
unordered_map<ll, int> dp; ll n;

bool factorize(ll &n, int b) {
	for (int i = 2; i < b; i++) {
		if (n % i) { continue; }
		pf.push_back({ i, 0 });
		while (n % i == 0) { pf.back().second++; n /= i; }
	}
	return n == 1;
}

void getDivisorsHelper(int i, ll curr, vector<pair<int, int>> &v) {
	if (i == (int)v.size()) { divi.push_back(curr); return; }
	getDivisorsHelper(i + 1, curr, pf);
	for (int j = 0; j < v[i].second; j++) {
		curr *= v[i].first;
		getDivisorsHelper(i + 1, curr, pf);
	}
}

int minNum(ll rem) {
	if (rem == 1) { return 0; }
	if (dp.count(rem)) { return dp[rem]; }

	int res = 100;
	for (int i = 1; i < (int)divi.size(); i++) {
		int d = (int) divi[i];
		if (d > rem) { break; }
		if (rem % d) { continue; }
		if (rem != n && d * d < b) { continue; }
		res = min(res, 1 + minNum(rem / d));
	}
	return dp[rem] = res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> b >> n; ll m = n;
	if (n == 1) { cout << 1 << endl; return 0; }
	if (!factorize(m, b)) { cout << "impossible" << endl; return 0; }
	getDivisorsHelper(0, 1, pf); sort(divi.begin(), divi.end());
	divi.erase(lower_bound(divi.begin(), divi.end(), b), divi.end());
	int res = minNum(n); vector<int> digits;
	while (n != 1) {
		for (int i = 1; i < (int)divi.size(); i++) {
			int d = (int)divi[i];
			if (n % d) { continue; }
			if (dp[n / d] + 1 != res) { continue; }
			digits.push_back(d); res--; n /= d; break;
		}
	}
	ll ans = 0;
	for (auto &x : digits) ans = ans * b + x;
	cout << ans << '\n';
	cin.ignore(2); return 0;
}