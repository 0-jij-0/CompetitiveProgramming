#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void find(const ll &n, ll l, ll r) {
	ll i = 0; int v = 1;
	while (v < n) {
		if (i + 2 * (n - v) >= l) { break; }
		i += 2 * (n - v); v++;
	}
	int cur = (v == n) ? 1 : v, next = v + 1; 
	bool b = true; i++; 
	while (i < l) {
		b = false; i++;
		if (i == l) { break; }
		b = true; i++;
		if (next == n) {
			if (cur == n - 1) { cur = 1; }
			else { cur++; next = cur + 1; }
		}
		else { next++; }
	}
	vector<int> res;
	while (i <= r) {
		if (b) { res.push_back(cur); b = false; i++; continue; }
		res.push_back(next);
		if (next == n) { 
			if (cur == n - 1) { cur = 1; }
			else { cur++; next = cur + 1; }
		}
		else { next++; }
		i++; b = true;
	}
	for (auto &x : res) { cout << x << ' '; }
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t; cin >> t;
	while (t--) { ll n, l, r; cin >> n >> l >> r; find(n, l, r); }
	cin.ignore(2); return 0;
}