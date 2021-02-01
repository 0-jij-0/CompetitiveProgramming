#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;

int main() {
	int n; cin >> n; v.resize(n);
	for (auto &x : v) { cin >> x; }
	sort(v.begin(), v.end());
	ll res = max(2 * v.back(), accumulate(v.begin(), v.end(), 0ll));
	cout << res << endl; cin.ignore(2); return 0;
}