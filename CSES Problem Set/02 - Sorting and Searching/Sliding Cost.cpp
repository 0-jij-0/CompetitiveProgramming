#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> v, res;
multiset<ll> lo, hi;
ll loS = 0, hiS = 0;

int main() {
	int n, k; cin >> n >> k; 
	v.resize(n); res.resize(n - k + 1);
	for (auto &x : v) { cin >> x; }
	for (int i = 0; i < k; i++) { lo.insert(v[i]); loS += v[i]; }
	while (hi.size() < lo.size()) { 
		loS -= *lo.rbegin(); hiS += *lo.rbegin();
		hi.insert(*lo.rbegin()); lo.erase(lo.find(*lo.rbegin()));
	}
	ll med = k % 2 ? *hi.begin() : *lo.rbegin();
	res[0] = lo.size() * med - loS + hiS - hi.size() * med;
	for (int i = k; i < n; i++) {
		if (lo.find(v[i - k]) != lo.end()) { loS -= v[i - k]; lo.erase(lo.find(v[i - k])); }
		else { hi.erase(hi.find(v[i - k])); hiS -= v[i - k]; }
		if (hi.empty() || v[i] < *hi.begin()) { lo.insert(v[i]); loS += v[i]; }
		else { hi.insert(v[i]); hiS += v[i]; }

		while (lo.size() < hi.size()) {
			loS += *hi.begin(); hiS -= *hi.begin();
			lo.insert(*hi.begin()); hi.erase(hi.find(*hi.begin()));
		}
		while (hi.size() < lo.size()) {
			loS -= *lo.rbegin(); hiS += *lo.rbegin();
			hi.insert(*lo.rbegin()); lo.erase(lo.find(*lo.rbegin()));
		}

		med = k % 2 ? *hi.begin() : *lo.rbegin();
		res[i - k + 1] = lo.size() * med - loS + hiS - hi.size() * med;
	}
	for (auto &x : res) cout << x << ' '; cout << '\n';
}