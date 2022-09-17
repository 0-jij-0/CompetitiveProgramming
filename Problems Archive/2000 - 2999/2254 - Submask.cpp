#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	for (ll m = n; m; m = (m - 1) & n)
		res.push_back(m); res.push_back(0);

	reverse(res.begin(), res.end());
	for (auto& x : res) cout << x << '\n';
}