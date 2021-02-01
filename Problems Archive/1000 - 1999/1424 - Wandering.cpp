#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
typedef long long ll;

vector<ll> v, prefMax;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto& x : v) { cin >> x; }
	partial_sum(v.begin(), v.end(), v.begin());

	prefMax.resize(n); prefMax[0] = v[0];
	for (int i = 1; i < n; i++)
		prefMax[i] = max(v[i], prefMax[i - 1]);

	ll cur = 0, res = 0;
	for (int i = 0; i < n; i++) {
		res = max(res, cur + prefMax[i]);
		cur += v[i];
	}
	cout << res << '\n';
	cin.ignore(2); return 0;
}