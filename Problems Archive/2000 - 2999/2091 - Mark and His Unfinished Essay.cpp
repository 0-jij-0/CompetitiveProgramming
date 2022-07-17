#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

string s; int n;

int query(ll k, vector<pair<ll, ll>>& v) {
	if (k < n) { return (int)k; }
	int i = 0; ll cur = n; while (cur <= k) {
		cur += v[i].second - v[i].first + 1; i++;
	}
	i--; while (i >= 0) {
		ll S = v[i].second - v[i].first + 1;
		if (k < cur - S) { cur -= S; i--; continue; }
		k = k - (cur -= S) + v[i--].first; 
	}
	return (int)k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t; while (t--) {
		int c, q; cin >> n >> c >> q >> s;
		vector<pair<ll, ll>> v(c);

		for (int i = 0; i < c; i++) {
			cin >> v[i].first >> v[i].second;
			--v[i].first; --v[i].second;
		}

		while (q--) {
			ll k; cin >> k; --k;
			cout << s[query(k, v)] << '\n';
		}
	}
}