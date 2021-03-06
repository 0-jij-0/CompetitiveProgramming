#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }

	ll res = 0; for (auto& x : v)
		res += x * x * (n - 1);

	ll s = accumulate(v.begin(), v.end(), 0ll);
	for (auto& x : v) res -= x * (s - x);
	cout << res << '\n'; cin.ignore(2); return 0;
}