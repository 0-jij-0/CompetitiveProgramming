#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v, dif; 
vector<int> d; int n;

bool check(int x) {
	for (int i = x; i < n; i += x)
		for (int j = 0; j < x; j++)
			if (dif[i + j] != dif[j]) return false;
	return true;
}

int main() {
	ll t; cin >> n >> t; 
	v.resize(n); dif.resize(n);
	for (auto& x : v) { cin >> x; }
	for (int i = 0; i < n - 1; i++)
		dif[i] = v[i + 1] - v[i];
	dif[n - 1] = (t - v[n - 1]) + v[0];

	for (int i = 1; i * i <= n; i++) if (n % i == 0) {
		d.push_back(i); if (i * i != n)d.push_back(n / i);
	}

	sort(d.begin(), d.end());
	for (auto& x : d) if (check(x)) {
		ll res = 0;
		for (int i = 0; i < x; i++) res += dif[i];
		cout << res - 1 << '\n'; break;		
	}
	
	cin.ignore(2); return 0;
}