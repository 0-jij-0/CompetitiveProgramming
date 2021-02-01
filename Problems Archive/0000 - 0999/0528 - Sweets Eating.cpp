#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> v, pref, res;

int main() {
	int n, m; cin >> n >> m;
	v.resize(n); pref.resize(n); res.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end()); ll pre = 0;
	for (int i = 0; i < n; i++) {
		pre += v[i]; pref[i] = pre;
	}
	for (int i = 0; i < m; i++) { res[i] = pref[i]; }
	for (int i = m; i < n; i++) { res[i] = pref[i] + res[i - m]; }
	for (auto &x : res) { cout << x << ' '; }
	cout << endl; cin.ignore(2); return 0;
}